#! /bin/bash

# This script makes snapshots of Reduce. It should be capable of
# building ones for Windows, Macintosh, Linux-i686, Linux-x86_64
# and the Raspberry Pi.
#
# Each snapshot needs to be built on a computer of the relevant type.
# This can either be the current local host, a remote host that is
# accessible using ssh (possibly via a gateway machine) or a virtual
# machine using virtualbox that is either local or remote.
# The exact set of machine to be used are set in a file "./snapshots"
# in the user's home directory, and a file called dot-snapshots here
# gives a prototype for that.
#
# Each host used during the build must have been set up with a comprehensive
# set of build tools and development libraries, and where it is to be
# accessed over ssh it must use public key authentication so that the current
# user on the system that this script runs on can access it without needing
# any extra interaction.
#
#                                                       ACN February 2018




#! /bin/sh
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
HERE=`dirname "$here"`

case $@ in
*help*)
  printf "$0: This script is for making snapshots of Reduce\n"
  printf "Usage: $0 machine1 machine2 ...\n"
  printf "where the supported 'machines' are\n"
  printf "    windows, macintosh, linux32, linux64 and rpi\n"
  printf "The two Linux variants refer to ones hosted on i686 and x86_64,\n"
  printf "and 'rpi' is a Raspberry Pi running raspbian.\n"
  printf "If no machines are listed the script will attempt to build all\n"
  printf "of them. The results will end up in a snapshots directory in the\n"
  printf "Reduce tree. The hosts used during the build can be adapted to\n"
  printf "local needs via a $HOME/.snapshots file, and scripts/dot-snapshots\n"
  printf "provides a prototype for such a file and some explanation of what\n"
  printf "needs to be present.\n"
  exit
  ;;
esac

# If you have a file called .snapshots in your home directory then that
# will be read here to establish machines to be used in the build. See later
# for details...

if test -f $HOME/.snapshots
then
  source $HOME/.snapshots
fi

printf ">>>>>>>>>>>>>>>>>>>> HERE=$HERE\n"

# There are a collection of issues that one needs to be aware of here...
# The various remote machines must provide the current user with ssh access
# without needing a password - ie they must have been set up with public key
# authentication. The ssh link must have been used already so that the
# system from which the link is initiated is already in the known_hosts file
# of the remote system. Both those constraints are there so that execution
# of a remote command doe snot requite any intervention.
# When the remote system is a Virtual machine then after it has been used
# to build stuff I want to switch it off. About the most safest way I can
# see to do that is to issue the command "sudo /sbin/shutdown -h now" on it.
# for this to work as required the user on that virtual machine needs
# passwordless superuser authority. One might reasonably have some level of
# concern about the security implications of that - I am going to take the
# view for now that this is a VIRTUAL machine and while it trusts its host
# nobody else needs to trust it (much). A possible alternative is to power off
# by using the virtualbox "controlvm acpipowerbutton" and ensure that the
# VM respond to that by closing down gracefully.

cd $HERE

# By directory names here can be absolute or relative. If they are specified
# as relative then they are reltive to the trunk directory in the Reduce
# tree that the snapshot builder is run from.

REDUCE_DISTRIBUTION="reduce-distribution"
REDUCE_BUILD="reduce-build"
SNAPSHOTS="snapshots"

prepare() {
# Ensure that there is a clean check-out of Reduce. If there is a directory
# called "$REDUCE_DISTRIBUTION" expect it to be a subversion checkout. Use
# revert to discard any local changes. Get rid of any files in it that have
# been added locally. Then use "svn update" to bring it into step with the
# repository. If this directory does not exist create it by checking out
# a copy from the central site.

  if test -d $REDUCE_DISTRIBUTION
  then
    printf "Will update and use existing $REDUCE_DISTRIBUTION file-set.\n"
    pushd $REDUCE_DISTRIBUTION >/dev/null
    svn -R revert .
# Get rid of any files that are in the local tree but are not present in the
# subversion repository. If "svn update" had a "--delete" option a bit like
# the one that rsync has or a bit like "Git clean" I would not have to
# use odd-looking shell scripting like this!
    svn st | grep '^?' | awk '{$1=""; print $0}' | xargs -I{} rm -rf '{}'
    svn update
    popd >/dev/null
  else
    printf "Will check out a new $REDUCE_DISTRIBUTION to use.\n"
    svn co svn://svn.code.sf.net/p/reduce-algebra/code/trunk \
           $REDUCE_DISTRIBUTION > reduce-checkout.log
  fi
}



build() {
# I will allow command-line options to indicate the collection
# of targets to be built for. This part of the script checks and decodes
# the options and dispatches to platform-specific scripts.

# First identify the current host machine. One could imagine adding more
# options here at some stage, but these are the ones I will initially
# consider building snapshots for or on.
  case `uname -s` in
  *CYGWIN*)
    local="windows"
    ;;
  *Darwin*)
    local="macintosh"
    ;;
  *Linux*)
    case `uname -m` in
    *x86_64*)
      local="linux64"
      ;;
    *i686*)
      local="linux32"
      ;;
    *arm*)
      local="rpi"
      ;;
    *)
      printf "Unsupported Linux variant (`uname -m`)\n"
      exit 1
      ;;
    esac
    ;;
  *)
    printf "Unknown system (`uname -s`)\n"
    exit 1
    ;;
  esac

# If no arguments are given I will default by building a  full set of
# snapshots.
  if test "$#" = "0"
  then
    ARGS="macintosh windows linux32 linux64 rpi"
  else
# Here (and in general through thsi script) I am going to assume that
# file-paths, machine-name and script arguments do not contain embedded
# whitespace, and so I do not need to be especially careful about quotation
# when expaning shell parameters.
    ARGS="$@"
  fi

# If there are arguments I check that each is a recognized system name and
# I collect them in a list - taking care that if the current platform is
# mentioned it will be placed at the end of the list.
  targets=""
  for a in $ARGS
  do
    case "$a" in
    windows | \
    linux32 | \
    linux64 | \
    rpi     | \
    macintosh)
      if test "$a" = "$local"
      then
        targets="$targets $a"
      else
        targets="$a $targets"
      fi
      ;;
    *)
      printf "\n### Option '$a' not recognized. Stopping.\n"
      exit 1
      ;;
    esac
  done

  printf "\nTargets: $targets\n"

# Now for all the systems that are to be built call the platform-specific
# function that will do the work.
  for TARGET in $targets
  do
# I will expect that there is a bash function to build for each possible
# target architecture.
    eval "build_$TARGET"
  done

}

build_windows() {
  machine_windows
  if test "$MODE" = "none"
  then
    printf "Unable to build Windows snapshot here\n"
    return 0
  fi
  start_remote_host
###
### I believe that I have not yet got the "--exclude" setting on the following
### line (and similar ones in a number of other places) right so that I avoid
### deleting what will later end up in the C directory...
###
  copy_files '$REDUCE_DISTRIBUTION/winbuild/'    '$REDUCE_BUILD/'  '--exclude=$REDUCE_DISTRIBUTION/winbuild/C'
  copy_files '$REDUCE_DISTRIBUTION/'             '$REDUCE_BUILD/C/'
  execute_in_dir '$REDUCE_BUILD/C'               './autogen.sh'
  execute_in_dir '$REDUCE_BUILD'                 'touch C.stamp'
  execute_in_dir '$REDUCE_BUILD'                 'make'
  fetch_files    '$REDUCE_BUILD/Output/*.*'      '$SNAPSHOTS/windows/'
  stop_remote_host
}

build_linux32() {
  machine_linux32
  build_debian linux32
}

build_linux64() {
  machine_linux64
  build_debian linux64
}

build_rpi() {
  machine_rpi
  build_debian rpi
}

build_debian() {
# Common code for building on a Linux variant
  if test "$MODE" = "none"
  then
    printf "Unable to build $TARGET snapshot here\n"
    return 0
  fi
  start_remote_host
  copy_files '$REDUCE_DISTRIBUTION/debianbuild/' '$REDUCE_BUILD/'   '--exclude=$REDUCE_DISTRIBUTION/debianbuild/C'
  copy_files '$REDUCE_DISTRIBUTION/'             '$REDUCE_BUILD/C/'
  execute_in_dir '$REDUCE_BUILD/C'               './autogen.sh'
  execute_in_dir '$REDUCE_BUILD'                 'touch C.stamp'
  execute_in_dir '$REDUCE_BUILD'                 'make'
  fetch_files    '$REDUCE_BUILD/*.{deb,rpm,tgz,bz2}'  "$SNAPSHOTS/$1/"
  stop_remote_host
}

build_macintosh() {
  machine_macintosh
  if test "$MODE" = "none"
  then
    printf "Unable to build Macintosh snapshot here\n"
    return 0
  fi
  start_remote_host
  copy_files '$REDUCE_DISTRIBUTION/macbuild/' '$REDUCE_BUILD/'   '--exclude=$REDUCE_DISTRIBUTION/macbuild/C'
  copy_files '$REDUCE_DISTRIBUTION/'          '$REDUCE_BUILD/C/'
  execute_in_dir '$REDUCE_BUILD/C'            './autogen.sh'
  execute_in_dir '$REDUCE_BUILD'              'make source-archive'
  execute_in_dir '$REDUCE_BUILD'              'touch C.stamp'
  execute_in_dir '$REDUCE_BUILD'              'make'
  fetch_files    '$REDUCE_BUILD/*.{dmg,bz2}'  '$SNAPSHOTS/macintosh'
  stop_remote_host
}

# The following functions arrange access to the machine on which building
# will take place. There are several possible configurations:
# (1) The current machine is to be used.
# (2) A machine reachable using ssh (with public key authentication so
#     no explicit password exchange is called for is needed) is to be used,
#     with the remote build performed relative to the current user's home
#     directory there.
# (3) A virtual machine is hosted on the current system and is to be used.
# (4) A virtual machine is hosted on a remote system and is to be used.
# (5) The machine to be used is on a private network accessible via
#     a machine that can be reached using ssh,
# I think that extending case (5) with a virtual machine hosted on a system
# that can only be accessed indirectly would be taking things too far, but if
# needbe I believe it could be supported.

# The host used and the mode of access to it will be passed in a selection
# of global variables which will need to be set ahead of calls to these
# functions. For now I will put in fixed settings, but in not too long
# I will arrange for distinct settings for each target architecture and for
# when the build runs on each possible host.

# The code here only deals with the "official Reduce snapshot machine",
# but by putting a file ".snapshots" in your home directory (and the
# file dot-snapshots here provides a model) you can get your own systems
# used instead.

machine_macintosh() {
  MODE="none"
# A user's .snapshots file can specify ports to use, but if it does not
# I will have a default.
  PORT=22022
# The function "hosts_macintosh" *MAY* have been defined in a user .snapshots
# file, and if so then I will call it here. But it does not have to be, so if
# the following line fails with a "command not found" error then that is
# entirely reasonable. That is why I redirect stderr to /dev/null.
  hosts_macintosh 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=local
# On this host the disc space is such that it is useful to specify that
# the work-space and eventual results from a snapshot build run are
# put in a separate volume... Note that the settings here are repeated for
# each target architecture.
      REDUCE_DISTRIBUTION="/Volumes/DATA/reduce-distribution"
      REDUCE_BUILD="/Volumes/DATA/reduce-build"
      SNAPSHOTS="/Volumes/DATA/snapshots"
      ;;
    *)
      printf "Do not know how to access a Macintosh from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}

machine_windows() {
  MODE="none"
  PORT=22022
  hosts_windows 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=virtual
      PORT=1001
      VM="REDUCE-pkg-factory-Windows"
      REDUCE_DISTRIBUTION="/Volumes/DATA/reduce-distribution"
      REDUCE_BUILD="/Volumes/DATA/reduce-build"
      SNAPSHOTS="/Volumes/DATA/snapshots"
      ;;
    *)
      printf "Do not know how to access a Windows machine from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}

machine_linux32() {
  MODE="none"
  PORT=22022
  hosts_linux32 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=virtual
      PORT=1002
      VM="REDUCE-pkg-factory-Ubuntu32"
      REDUCE_DISTRIBUTION="/Volumes/DATA/reduce-distribution"
      REDUCE_BUILD="/Volumes/DATA/reduce-build"
      SNAPSHOTS="/Volumes/DATA/snapshots"
      ;;
    *)
      printf "Do not know how to access an i686 Linux machine from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}

machine_linux64() {
  MODE="none"
  PORT=22022
  hosts_linux64 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=virtual
      PORT=1003
      VM="REDUCE-pkg-factory-Ubuntu"
      REDUCE_DISTRIBUTION="/Volumes/DATA/reduce-distribution"
      REDUCE_BUILD="/Volumes/DATA/reduce-build"
      SNAPSHOTS="/Volumes/DATA/snapshots"
      ;;
    *)
      printf "Do not know how to access an x86_64 Linux machine from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}

machine_rpi() {
  MODE="none"
  PORT=22022
  hosts_rpi 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    *)
      printf "Do not know how to access a Raspberry Pi from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}


# Now I have the recipes that can be used to transfer files or execute
# commands. Each tests MODE to see what to do.
  
# If I am connecting to a Virtual Machine I will disable host key checking
# and recording so that I can connect for the very first time without
# that causing confusion, and so that reconfiguration of the VM does not
# lead to pain.

SSHOPTS="-o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no\
 -o LogLevel=error -o ForwardX11=no"

start_remote_host() {
# This is only required if a virtual machine is involved. There are two
# cases - one when the machine is hosted on the current system and the
# other when it is remote.
  case $MODE in
  virtual)
# If the VM happens to be running already (perhaps left over from an
# interrupted previous attempt) I need to shut it down before I try
# to re-configure it. Note that all this will just stall if the VM
# you are trying to work with does not exist! I check for "running" here
# because a machine might be labelled as "aborted" or "stopped" or various
# other states. If the machine is already in the process of stopping then
# it might have done so before the ACPI even is posted to it and that might
# lead to a message suggesting an error, but all ought to be well.
    printf "vboxmanage showvminfo --machinereadable $VM\n"
    if vboxmanage showvminfo --machinereadable $VM | grep 'VMState="running"'
    then
      stop_remote_host
    fi
# If there is a VM on the local machine I start by re-configuring it so that
# local port $PORT is redirected to its port 22 (ie ssh).
    printf "vboxmanage modifyvm $VM --natpf1 delete ssh\n"
    vboxmanage modifyvm $VM --natpf1 delete ssh 2> /dev/null
    printf "vboxmanage modifyvm $VM --natpf1 \"ssh,tcp,,$PORT,,22\"\n"
    vboxmanage modifyvm $VM --natpf1 "ssh,tcp,,$PORT,,22"
# Start up the machine.
    printf "vboxmanage startvm $VM --type headless\n"
    vboxmanage startvm $VM --type headless
# Now here I would like to use "vboxmanage guestproperty wait $VM" on a
# suitable key to wait until the VM is started. However on at least one of my
# VMs I find that that information required does not manage to filter back
# to the host. So I drop back to polling via ssh every 10 seconds.
    printf "Poll at $USER@localhost port $PORT\n"
    while :
    do
      sleep 10
      printf "ssh -p $PORT $SSHOPTS $USER@localhost printf \"hello\"\n"
      hello=`timeout 20 ssh -p $PORT $SSHOPTS $USER@localhost printf "hello"`
      if test "x$hello" = "xhello"
      then
        break
      else
        printf "Response: $hello\n"
      fi
    done
    ;;
  ssh+virtual)
# Now I express a similar sequence of steps, but with the Virtual Machine
# being created on a remote host.
    printf "ssh $HOST vboxmanage showvminfo --machinereadable $VM\n"
    if ssh $HOST vboxmanage showvminfo --machinereadable $VM | grep 'VMState="running"'
    then
      stop_remote_host
    fi
    printf "ssh $HOST vboxmanage modifyvm $VM --natpf1 delete ssh\n"
    ssh $HOST vboxmanage modifyvm $VM --natpf1 delete ssh 2> /dev/null
    printf "ssh $HOST vboxmanage modifyvm $VM --natpf1 \"ssh,tcp,,$PORT,,22\"\n"
    ssh $HOST vboxmanage modifyvm $VM --natpf1 "ssh,tcp,,$PORT,,22"
    printf "ssh $HOST vboxmanage startvm $VM --type headless\n"
    ssh $HOST vboxmanage startvm $VM --type headless
    printf "Poll at $USER@$HOST port $PORT\n"
    while :
    do
      sleep 10
      printf "ssh -p $PORT $SSHOPTS $USER@$HOST printf \"hello\"\n"
      hello=`timeout 20 ssh -p $PORT $SSHOPTS $USER@$HOST printf "hello"`
      if test "x$hello" = "xhello"
      then
        break
      else
        printf "Response: $hello\n"
      fi
    done
    ;;
  esac
}

# All the options to rsync here say
#   r recursive copy
#   l copy symlinks
#   H copy hard links
#   p preserve permissions
#   E preserve executability
#   P keep any partially copied files for smoother re-start after
#     interruption
#   t preserve modification times of files
#   z compress network traffic
#   e use ssh with a specified port number
#   --exclude=... avoid sending certain files & directories
#   --delete get rid of files not in the local file-set
#   --force perform actions without requiring confirmation
#   --info=... control messages that are generated
#

RSYNC_OPTIONS="-rlHpEPtz --delete --force \
   --info=backup0,copy0,del0,flist0,misc0,mount0 \
   --info=name0,progress0,remove0,skip0,symsafe2,stats2"

# NOTE HORRIBLY WELL. On the Macintosh there is a version of rsync in
# /usr/bin, but it is an old one. The settings of PATH that put the newer
# version (from macports) ahead of it for normal use does not apply when
# executing a remote command here. So the "--rsync-path" directive to
# direct use of the macports version is needed if the "--info" option is
# to be accepted to control the amount of displayed trace information.

MAC_RSYNC_EXTRA="--rsync-path=/opt/local/bin/rsync"

copy_files() {
# Usage example : copy_files '$REDUCE_DISTRIBUTION/macbuild/' '$REDUCE_BUILD/' '--exclude...'
  if test "$1" = "" || test "$2" = ""
  then
    printf "Internal error\n"
    exit 1
  fi
  src="$1"
  dest="$2"
# The third argument is optional, but passes additional options to rsync.
  xtra="$3"
  if test "$TARGET" = "macintosh"
  then
    RSO="$RSYNC_OPTIONS --exclude=.svn $xtra --delete $MAC_RSYNC_EXTRA"
  else
    RSO="$RSYNC_OPTIONS --exclude=.svn $xtra --delete"
  fi
  printf "Mode = $MODE: copy from $src to $dest\n"
  case $MODE in
  local)
    cd $HERE
    printf "rsync $RSO $src $dest\n"
    rsync $RSO $src $dest
    ;;
  ssh)
# For direct ssh access I will expect that the remote machine has been
# accessed before and that host key confirmation etc has been performed.
    printf "rsync $RSO $src $USER@$HOST:$dest\n"
    rsync $RSO $src $USER@$HOST:$dest
    ;;
  virtual)
    printf "rsync $RSO -e \"ssh -p $PORT $SSHOPTS\" $src $USER@localhost:$dest\n"
    rsync $RSO -e "ssh -p $PORT $SSHOPTS" $src $USER@localhost:$dest
    ;;
  ssh+ssh)
    printf "rsync $RSO -e \"ssh $SSHOPTS $USER@$HOST1 ssh $SSHOPTS\" $src $USER@$HOST2:$dest\n"
    rsync $RSO -e "ssh $SSHOPTS $USER@$HOST1 ssh $SSHOPTS" $src $USER@$HOST2:$dest
    ;;
  ssh+virtual)
    printf "rsync $RSO -e \"ssh -p $PORT $SSHOPTS\" $src $USER@$HOST:$dest\n"
    rsync $RSO -e "ssh -p $PORT $SSHOPTS" $src $USER@$HOST:$dest
    ;;
  *)
    printf "Unknown mode: $MODE\n"
    exit 1
  esac
}

execute_in_dir() {
# Usage example: execute_in_dir '$REDUCE_BUILD/C' './autogen.sh'
  if test "$1" = "" || test "$2" = ""
  then
    printf "Internal error\n"
    exit 1
  fi
  dir="$1"
  cmd="$2"
  if test "$TARGET" = "macintosh"
  then
# For execution on the Macintosh I need to ensure that I have macports stuff
# on my PATH.
    cmd="export PATH=/opt/local/bin:\$PATH; $cmd"
  fi
  printf "Mode = $MODE: execute $cmd in directory $dir\n"
  case $MODE in
  local)
    cd $HERE
    printf "eval \"cd $dir; $cmd\"\n"
    eval "cd $dir; $cmd"
    cd $HERE
    ;;
  ssh)
    printf "ssh $USER@$HOST \"cd $dir; $cmd\"\n"
    ssh $USER@$HOST "cd $dir; $cmd"
    ;;
  virtual)
    printf "ssh -p $PORT $SSHOPTS $USER@localhost \"cd $dir; $cmd\"\n"
    ssh -p $PORT $SSHOPTS $USER@localhost "cd $dir; $cmd"
    ;;
  ssh+ssh)
# I had trouble getting the quotation correct here, so now I build up
# the command that is to be executed step by step. Note that within $cmd there
# can be the sequence "PATH=xxx:$PATH" and the expansion of "$PATH" has to
# be delayed so it is performed on the final server.
    cmd="cd $dir; $cmd"
# Now create a command that will execute stuff on the final system.
    cmd="ssh $SSHOPTS $USER@$HOST2 '$cmd'"
    printf "ssh $SSHOPTS $USER@$HOST1 \"$cmd\"\n"
    ssh $SSHOPTS $USER@$HOST1 "$cmd"
    ;;
  ssh+virtual)
    printf "ssh -p $PORT $SSHOPTS $USER@$HOST \"cd $dir; $cmd\"\n"
    ssh -p $PORT $SSHOPTS $USER@$HOST "cd $dir; $cmd"
    ;;
  *)
    printf "Unknown mode: $MODE\n"
    exit 1
  esac
}

fetch_files() {
# Usage example: fetch_files '$REDUCE_BUILD/*.{dmg,bz2}' '$SNAPSHOTS/'
  if test "$1" = "" || test "$2" = ""
  then
    printf "Internal error\n"
    exit 1
  fi
  src="$1"
  dest="$2"
  mkdir -p $dest
# I will move any previous snapshots for this architecture to somewhere
# else.
  mkdir -p old$dest
  printf "cp -r ${dest}* old$dest\n"
  cp -r ${dest}* old$dest
# This function is perhaps more delicate than others, because the source
# argument may be a list of files using wildcards. The wildcards must be
# expanded on the remote machine not locally. I will delete any old snapshots
# for this target as I copy the new ones across.
  if test "$TARGET" = "macintosh"
  then
    RSO="$RSYNC_OPTIONS --delete $MAC_RSYNC_EXTRA"
  else
    RSO="$RSYNC_OPTIONS --delete"
  fi
  printf "Mode = $MODE: copy $src to $dest\n"
  case $MODE in
  local)
    cd $HERE
    printf "eval \"rsync $RSO $src $dest\"\n"
    eval "rsync $RSO $src $dest"
    ;;
  ssh)
    printf "rsync $RSO \"$USER@$HOST:$src\" $dest\n"
    rsync $RSO "$USER@$HOST:$src" $dest
    ;;
  virtual)
    printf "rsync $RSO -e \"ssh -p $PORT $SSHOPTS\" \"$USER@localhost:$src\" $dest\n"
    rsync $RSO -e "ssh -p $PORT $SSHOPTS" "$USER@localhost:$src" $dest
    ;;
  ssh+ssh)
    printf "rsync $RSO -e \"ssh $SSHOPTS $USER@$HOST1 ssh $SSHOPTS\" \"$USER@$HOST2:$src\" $dest\n"
    rsync $RSO -e "ssh $SSHOPTS $USER@$HOST1 ssh $SSHOPTS" "$USER@$HOST2:$src" $dest
    ;;
  ssh+virtual)
    printf "rsync $RSO -e \"ssh -p $PORT $SSHOPTS\" \"$USER@$HOST:$src\" $dest\n"
    rsync $RSO -e "ssh -p $PORT $SSHOPTS" "$USER@$HOST:$src" $dest
    ;;
  *)
    printf "Unknown mode: $MODE\n"
    exit 1
  esac
}

stop_remote_host() {
# If I am using a virtual machine I will close it by using its (virtual)
# ACPI power button.
  case $MODE in
  virtual)
    printf "vboxmanage controlvm $VM acpipowerbutton\n"
    vboxmanage controlvm $VM acpipowerbutton
# In general a virtual machine will not shut down promptly when its power
# button is pressed. It may delay to give users a chance to tidy up and it
# may install updates or do other system administrative tasks. So I will
# wait until vboxmanage confirms to me that the system is actually powered
# off.
    while :
    do
      sleep 10
      printf "vboxmanage showvminfo --machinereadable $VM\n"
      if vboxmanage showvminfo --machinereadable $VM | grep 'VMState="poweroff"'
      then
        break
      fi
    done
    ;;
  ssh+virtual)
    printf "ssh $HOST vboxmanage controlvm $VM acpipowerbutton\n"
    ssh $HOST vboxmanage controlvm $VM acpipowerbutton
    while :
    do
      sleep 10
      printf "ssh $HOST vboxmanage showvminfo --machinereadable $VM\n"
      if ssh $HOST vboxmanage showvminfo --machinereadable $VM | grep 'VMState="poweroff"'
      then
        break
      fi
    done
    ;;
  esac
}

#########################################################################
# Now do the work.

cd $HERE
prepare
cd $HERE
build "$@"
cd $HERE

exit 0

# end of testsnaps.sh