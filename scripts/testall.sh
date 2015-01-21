#! /bin/sh

# Test all package

# Usage:
#    scripts/testall.sh [--install]        test everything
#    scripts/testall.sh [--install] --csl   test just the CSL version
#    scripts/testall.sh [--install] --psl   test just the PSL version

# The flags are mostly handled by being passed down to the test1.sh script

install=
case ${1:-x} in
--install)
  install=--install
  shift
  ;;
esac

if test $# = 0
then
  csl="yes"
  psl="yes"
else
  if test $# = 1
  then
    case $1 in
    --csl)
      csl="yes"
      psl="no"
      ;;
    --psl)
      csl="no"
      psl="yes"
      ;;
    *)
      echo "scripts/testall.sh [--csl or --psl]"
      exit 1
      ;;
    esac
  else
    echo "scripts/testall.sh [--csl or --psl]"
    exit 1
  fi
fi

# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

here=`dirname "$0"`
here=`cd "$here" ; pwd`
here=`dirname "$here"`

#
# Remove old log files
#
rm -f csl-times/*.rlg* psl-times/*.rlg* csl-psl-times-comparison/*.rlg.diff

packages=`sed -e '/^\%/d' $here/packages/package.map | \
          grep ' test ' | \
          sed -e 's/(//; s/".*//'`
for p in $packages
do
  echo "Test package $p"
  $here/scripts/test1.sh $install $* $p
done

for p1 in $here/packages/regressions/*.tst
do
  p=${p1%.tst}
  p=${p##*/}
  echo "Test regression case $p"
  $here/scripts/test1.sh $install $* regressions $p
done

if test "$csl" = "yes"
then
  csldiffs=`cd csl-times ; echo *.rlg.diff`
fi
if test "$psl" = "yes"
then
  psldiffs=`cd psl-times ; echo *.rlg.diff`
fi
if test "$csl" = "yes" && test "$psl" = "yes"
then
  cslpsldiffs=`cd csl-psl-times-comparison ; echo *.rlg.diff`
fi

echo
if test "$csl" = "yes"
then
  if test "$psl" = "yes"
  then
    echo "Summary of CSL and PSL test runs"
    echo "================================"
    echo
    test "$csldiffs" != "*.rlg.diff" && echo "Differences for CSL:" `echo $csldiffs | sed -e 's/\.rlg\.diff//g'`
    echo
    test "$psldiffs" != "*.rlg.diff" && echo "Differences for PSL:" `echo $psldiffs | sed -e 's/\.rlg\.diff//g'`
    echo
    test "$cslpsldiffs" != "*.rlg.diff" && echo "Differences between CSL and PSL :" `echo $cslpsldiffs | sed -e 's/\.rlg\.diff//g'`
  else
    echo "Summary of CSL test runs"
    echo "========================"
    echo
    test "$csldiffs" != "*.rlg.diff" && echo "Differences for CSL:" `echo $csldiffs | sed -e 's/\.rlg\.diff//g'`
  fi
else
  echo "Summary of PSL test runs"
  echo "========================"
    test "$psldiffs" != "*.rlg.diff" && echo "Differences for PSL:" `echo $psldiffs | sed -e 's/\.rlg\.diff//g'`
    echo
fi
echo

if test "x`which dc`" != "x"
then

  if test "$csl" = "yes"
  then
    csltotal="0"
    for x in csl-times/*.time
    do
      val=`grep ^Time $x | sed -e 's/.*(counter 1): //; s/ms.*//'`
# The apparently spurious "0" here is in case $val ends up as empty.
      csltotal=`printf "1k 0 %s %s + pq" $val $csltotal | dc`
    done
    csltotal=`printf "2k %s 1000 / pq" $csltotal | dc`
    printf "CSL total = %s (seconds)\n" $csltotal
  fi

  if test "$psl" = "yes"
  then
    psltotal="0"
    for x in psl-times/*.time
    do
      val=`grep ^Time $x | sed -e 's/.*(counter 1): //; s/ms.*//'`
      psltotal=`printf "1k 0 %s %s + pq" $val $psltotal | dc`
    done
    psltotal=`printf "2k %s 1000 / pq" $psltotal | dc`
    printf "PSL total = %s (seconds)\n" $psltotal
  fi

fi

# end of script




