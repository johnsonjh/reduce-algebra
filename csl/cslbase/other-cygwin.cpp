// other-cygwin.cpp                     Copyright (C) A C Norman  2014-2020

//
// This program is to be run from a DOS command prompt or any cygwin
// shell, and it "changes gear" so that the command that it is
// given as its arguments is run in a full cygwin context.
// It is capable of running its target in the version of cygwin it is
// not run from - ie if launched from a 32-bit terminal it can
// run a 64-bit application and vice versa.
// Note that for good behaviour in such usage that mixes 32 and 64-bit
// cygwin working it will be important that file systems map so that
// relevant files appear in consistent places from both 32 and 64-bit
// worlds. This may be easiest if paths are fully rooted and so always
// start /cygdrive/x/...
// In particular BEWARE of home directories!
//
// You must compile this with i686-w64-mingw32-gc++.
// For this to work you (obviously) must have both the 32 and 64-bit
// versions of cygwin installed such that the current user can access them.
// The code here will probe the Windows registry to try to find where they
// have been installed - that will very often be in c:\cygwin and c:\cygwin64.
// Anybody who has or once had multiple instances of cygwin installed (apart
// from one 32-bit and one 64-bit) MAY be lucky but I will not make any
// guarantees. 
//
// When compiled without command line flags this executes the command it
// is given in the opposite version of cygwin to whichever is is invoked
// from. If it is compiled with FORCE32 or FORCE64 set it will ensure that
// the command is executed in the specifed context.
//
// If called without any explicit command to execute then this will display
// an indication of which versions of cygwin it believes are available.
// that may be useful at configure time. This will be in the form "32"
// "64", "32 64" or a moaning message that no Cygwin installation can be
// identified.
//
// [2020] Cygwin changes (I believe that will be whait it is) led to
// output from the spawned command being lost.

/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/


// $Id$



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <windows.h>
#include <tlhelp32.h>
#include <unistd.h>
#include <process.h>
#include <thread>

static bool run64;

#define LONGEST_COMMAND 4096

static char command[LONGEST_COMMAND] = {0};

// Here I have a string s and I want to end up with 's' in the command.
// However I am in a context where the command is itself already being
// written within (single) quotes, so I have a messy notation to use to
// include the quote marks.

void append_command(char *s)
{   char *p = command;
    while (*p != 0 && p < &command[LONGEST_COMMAND]) p++;
    if (p > &command[LONGEST_COMMAND-16])
    {   std::fprintf(stderr, "\n+++ Command line too long\n");
        std::exit(1);
    }
    *p++ = '\\';
    *p++ = '\"';
    int c;
    while ((c = *s++) != 0)
    {   if (c == '&' || c == '\\' || c == '<' || c == '>' ||
            c == '^' || c == '|') *p++ = '^';
        if (c == '\"' || c == '\\') *p++ = '\\';
        *p++ = c;
        if (p > &command[LONGEST_COMMAND-16])
        {   std::fprintf(stderr, "\n+++ Command line too long\n");
            std::exit(1);
        }
    }
    *p++ = '\\';
    *p++ = '\"';
    *p = 0;
}

// The following code was found in newsgroup postings, and I believe it was
// intended to be available for re-use.

// Find a process with a given id in a snapshot

BOOL FindProcessID(HANDLE snap, DWORD id, LPPROCESSENTRY32 ppe)
{   BOOL res;
    ppe->dwSize = sizeof(PROCESSENTRY32); // (mandatory)
    res = Process32First(snap, ppe);
    while (res)
    {   if (ppe->th32ProcessID == id) return TRUE;
        res = Process32Next(snap, ppe);
    }
    return FALSE;
}

// Get the parent process id of the current process

BOOL GetParentProcessId(DWORD* parent_process_id)
{   HANDLE hSnap;
    PROCESSENTRY32 pe;
    DWORD current_pid = GetCurrentProcessId();

    // Take a snapshot of all Windows processes
    hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hSnap) return FALSE;

    // Find the current process in the snapshot
    if (!FindProcessID(hSnap, current_pid, &pe)) return FALSE;

    // Close the snapshot
    if (!CloseHandle(hSnap)) return FALSE;

    *parent_process_id = pe.th32ParentProcessID;
    return TRUE;
}

static char cygwin_root[256];
static char cygwinized_root[256];

bool find_cygwin(bool sixty_four)
{
// Here I wish to find a cygwin installation (of the given word-length).
// I will look in the registry under HKCU\Software\cygwin\Installations.
// I will return true on success.
    HKEY hKey;
    cygwin_root[0] = 0;
    if (RegOpenKeyEx(HKEY_CURRENT_USER,
                     TEXT("Software\\cygwin\\Installations"),
                     0,
                     KEY_READ,
                     &hKey) == ERROR_SUCCESS) 
    {
// If the key was not present then I do not seem to have any cygwin
// copies at all. If I do I will want to see where they live, and before
// I extract information from the registry I need to know how large the
// records that I will extract might be.
        DWORD n_name, n_data;        // max size of fields in registry
        DWORD rc = RegQueryInfoKey(
            hKey,                    // key handle
            NULL,                    // buffer for class name
            NULL,                    // size of class string
            NULL,                    // reserved
            NULL,                    // number of subkeys
            NULL,                    // longest subkey size
            NULL,                    // longest class string
            NULL,                    // number of values for this key
            &n_name,                 // longest value name
            &n_data,                 // longest value data
            NULL,                    // security descriptor
            NULL);                   // last write time
// I create space for the returned value plus a terminating NUL. If the
// allocation fails then an exception will be raised an the program will
// terminate.
        TCHAR *name = new TCHAR [n_name+1];
        BYTE *data = new BYTE [n_data+1];
// Scan all the registry data associated with this key. The index i tracks
// which entry is returned, but there is no guarantee of material being
// send back to me in any particular order.
        for (DWORD i=0;; i++)
        {   DWORD type;
            DWORD namesize = n_name+1;    // allow for terminating NUL
            DWORD datasize = n_data+1;
            rc = RegEnumValue(
                hKey,                     // Key
                i,                        // Index
                name,                     // put name here
                &namesize,                // name size
                NULL,                     // Reserved - must be NULL
                &type,                    // put type here
                data,                     // put data here
                &datasize);               // data size
// The key error code here is ERROR_NO_MORE_ITEMS, but I will abandon my
// scan on any error, and not alert users to just what it was.
            if (rc != ERROR_SUCCESS) break;
            if (type != REG_SZ) continue; // Ignore non SZ values
// The data returned here might be something like
//        "\??\C:\cygwin64"
// where the "\??" part at the front is not an accident - it is s Windows
// path component stressing that the part "C:" is what you expect it to
// mean in Windows. WHile one can EXPECT that the final component will be
// either cygwin or cygwin64 thers is no guarantee of that... nor that the
// choice of 32 vs 64-bit cygwin relates neatly to the directory path.
// To see if this is a plausible cygwin installation I will look for
// xxx/bin/cygwin1.dll and xxx/bin/bash.exe and for each of those I will
// look for PE headers that might confirm that they looked like a DLL and
// and executable and on that basis work out whether they are 32 or 64-bit
// variants.
            char *p = (char *)data;
// Verify that the data starts of "\??\x:\" as expected. Also ignore any
// cases where the string is unreasonably long.
            if (p[0] != '\\' ||
                p[1] != '?' ||
                p[2] != '?' ||
                p[3] != '\\' ||
                !std::isalpha(p[4]) ||
                p[5] != ':' ||
                p[6] != '\\' ||
                std::strlen(p) > 200) continue;
            char path1[256], path2[256];
            std::sprintf(path1, "%s\\bin\\cygwin1.dll", p+4);
            std::sprintf(path2, "%s\\bin\\bash.exe", p+4);
            std::FILE *f1 = std::fopen(path1, "rb");
            std::FILE *f2 = std::fopen(path2, "rb");
// If the file does not exist or is not readable then this is not a good
// candidate.
            if (f1 == NULL)
            {   if (f2 != NULL) std::fclose(f2);
                continue;
            }
            if (f2 == NULL)
            {   std::fclose(f1);
                continue;
            }
            IMAGE_DOS_HEADER dos_header1, dos_header2;
            if (std::fread(&dos_header1, sizeof(dos_header1), 1, f1) == 1 &&
                dos_header1.e_magic == IMAGE_DOS_SIGNATURE &&
                std::fread(&dos_header2, sizeof(dos_header2), 1, f2) == 1 &&
                dos_header2.e_magic == IMAGE_DOS_SIGNATURE)
            {   LONG next1 = dos_header1.e_lfanew,
                     next2 = dos_header2.e_lfanew;
                IMAGE_NT_HEADERS nt_headers1, nt_headers2;
                if (std::fseek(f1, next1, SEEK_SET) == 0 &&
                    std::fread(&nt_headers1, sizeof(nt_headers1), 1, f1) == 1 &&
                    nt_headers1.Signature == IMAGE_NT_SIGNATURE &&
                    std::fseek(f2, next2, SEEK_SET) == 0 &&
                    std::fread(&nt_headers2, sizeof(nt_headers2), 1, f2) == 1 &&
                    nt_headers2.Signature == IMAGE_NT_SIGNATURE)
                {
// The machine type is expected to be either IMAGE_FILE_MACHINE_I386 for
// a 32-bit image or IMAGE_FILE_MACHINE_AMD64 for 64-bit.
                    bool ok;
                    if (sixty_four)
                        ok = nt_headers1.FileHeader.Machine ==
                                 IMAGE_FILE_MACHINE_AMD64 &&
                             nt_headers2.FileHeader.Machine ==
                                 IMAGE_FILE_MACHINE_AMD64;
                    else
                        ok = nt_headers1.FileHeader.Machine ==
                                 IMAGE_FILE_MACHINE_I386 &&
                             nt_headers2.FileHeader.Machine ==
                                 IMAGE_FILE_MACHINE_I386;
// Wow - now  may have found a nice installation. Well there is some messy
// possibility that I might find several locations corresponding to
// multiple cygwin installations. I think that ought not to be the situation,
// but I can still worry about it. I will keep the one where its path
// is shortest, and if there are several with the same path length I will
// keep the one that comes alphabetically earliest. This should mean that
// I prefer (eg) C:\cygwin to D:\cygwin and both of those to C:\old\cygwin.
                    if (ok &&
                        (cygwin_root[0] == 0 ||
                         (std::strlen(p+4) <= std::strlen(cygwin_root) &&
                          std::strcmp(p+4, cygwin_root) < 0)))
                          std::strcpy(cygwin_root, p+4);
                }
            }
            std::fclose(f1);
            std::fclose(f2);
        }
        delete [] data;
    }
    RegCloseKey(hKey);
    return cygwin_root[0] != 0;
}

static void echoOutput(HANDLE h)
{   char buffer[4];
    DWORD actual;
    for (;;)
    {   BOOL fg = ReadFile(h, buffer, 1, &actual, NULL);
        if (!fg || actual!=1) break;
        std::putchar(buffer[0]);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {   bool c32 = find_cygwin(false);
        bool c64 = find_cygwin(true);
// In general I will be expecting that this program is called from a cygwin
// shell...
        std::printf("%s\n",
            !c32 && !c64 ? "No cygwin installation at all found!\n" :
            !c32 && c64  ? "64" :
            c32 && !c64  ? "32" :
                           "32 64");
        return 0;
    }
    run64 = false;
    DWORD parent;
    if (!GetParentProcessId(&parent))
    {   std::printf("Parent process not found\n");
        return 1;
    }
    HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION|
                           PROCESS_QUERY_LIMITED_INFORMATION,
                           TRUE,
                           parent);
    BOOL b;
    if (IsWow64Process(h, &b) == 0)
    {   std::printf("isWow64Process() failed\n");
        return 1;
    }
    if (b) run64 = true;
    else
    {   SYSTEM_INFO s;
        GetNativeSystemInfo(&s);
        switch (s.wProcessorArchitecture)
        {   case PROCESSOR_ARCHITECTURE_AMD64:
                run64 = false;
                break;
            case PROCESSOR_ARCHITECTURE_INTEL:
#ifndef FORCE32
                std::printf("You seem to be running 32-bit operating system\n");
                std::printf("This utility can not work. Exiting\n");
                return 1;
#else
                break;
#endif
            default:
                std::printf("Unknown platform: exiting.\n");
                return 1;
        }
    }

// At this stage run64 is set to indicate the opposite of the shell currently
// in use. That would be the default shell that one wants to end up in.
// If one of the FORCE options is enabled then override that dynamic test.
    bool running64 = !run64;

#if defined FORCE64
    run64 = true;
#elif defined FORCE32
    run64 = false;
#endif

// Now I know which version of cygwin I want to run a command under, and
// so I will check what versions are available.

    if (!find_cygwin(run64))
    {   std::printf("No %d bit version of cygwin found. Sorry\n",
               run64 ? 64 : 32);
        return 1;
    }

    STARTUPINFO startup;
    PROCESS_INFORMATION process;
    const char *user;
    char newenv[1024];
    int dirsize, i, rc;
    std::memset((void *)&startup, 0, sizeof(startup));
    std::memset((void *)&process, 0, sizeof(process));
    startup.cb = sizeof(startup);
// Passing STD_OUTPUT etc down seems to behave well when I am under mintty
// or an xterm, but if I am running in a Windows console (eg as in the
// earlier way that cygwin was set up) this is a mess in that output
// does not appear on my console. I can go
//    cyg64 "whoami > xxx"
// and the information ends up in the file xxx in the way it should, so
// this is perhaps a case where I need to create a pipe to pass down
// as each of stdout and stderr. Once I have launched the program I then need
// to read from both of those and transfer anything I get back to my own
// standard outputs. It also seems that STD_INPUT is passed OK here if it is
// a pipe, but not if it is interactive... Ah well maybe this is still good
// enough for IMMEDIATE purposes even without the upgrades needed to sort
// out the problems described here! But please be aware that some output can
// get misdirected along the way!
//
// The bad behaviour explained as above now seems to arise under mintty as
// well as from a Windows console. But it looks as if xterm is still OK!
    HANDLE p1a, p1b, p2a, p2b;
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL; 
    if (!CreatePipe(&p1a, &p1b, &sa, 0) ||
        !CreatePipe(&p2a, &p2b, &sa, 0))
    {   std::printf("Failed to create pipes\n");
        std::exit(1);
    }
    SetHandleInformation(p1b, HANDLE_FLAG_INHERIT, 0);
    SetHandleInformation(p2a, HANDLE_FLAG_INHERIT, 0);
    startup.hStdInput = p1a;
    startup.hStdOutput = p2b;
    startup.hStdError = p2b;
    startup.wShowWindow = SW_HIDE;
    startup.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
// Now set up a command line
    const char *pnewdir = NULL;
    char *pnewenv = NULL;
    char *current;
// What I do here is to create a string that contains
//    windir\system32\cmd /c
//         "c:\cygwin64\bin\bash --login -c
//          \"cd DIRECTORY; c1; c2; ...\""
// so first "cmd /c "..." will remove the first and final double quotes
// on the line but leave all the rest exactly as is.
// Then "bash -c '...'" uses the single quotes there to arrange that a single
// string is provided as an operand for "-c". This will involve a sequence of
// items that must each parse as a single word, and which (being within single
// quotes) must have escapes and quote marks in them protected.
// Well within the '...' if an embedded single quote is required it must be
// rendered as '\'' - that ends the string, puts in an individual single quote
// by escaping it with a backslash and then resumes the string.
//
// If I am NOT needing to flip which version of cygwin I am using I can try
// use of a command line "bash -c \"c1; c2; ...\""
// and avoid starting up cygwin from scratch again.
//
    char newdir[1024];
 
    if (run64 == running64)
    {
// The command I issue here will be interpreted by Windows, but I should have
// the environment and current directory as for Cygwin. So I say just "bash"
// at the front not "/bin/bash" because the command-name needs to be a
// Windows version.
        std::sprintf(command, "bash -c \"");
        for (i=1; i<argc; i++)
        {   append_command(argv[i]);
            if (i != argc-1) std::strcat(command, " ");
        }
        std::strcat(command, "\"");
    }
    else
    {
// Under cygwin the shell variable USER gives the effective user name. A
// second variable USERNAME holds the name of the user that Windows believes
// is active: eg when I am linked in over ssh that may be "cyg_server".
// If I fail to read USER I will default to the name "unknown".
        user = std::getenv("USER");
        if (user == NULL) user = "unknown";
        std::memset(newenv, 0, sizeof(newenv));
// I need a variant on cygwin_root converted from x:\... to /cygdrive/x/...
        std::sprintf(cygwinized_root, "/cygdrive/%c%s",
             cygwin_root[0], &cygwin_root[2]);
        for (char *p=cygwinized_root; *p!=0; p++)
            if (*p == '\\') *p = '/';
        std::sprintf(newenv, "OTHER=yes%cUSER=%s%cPATH=%s/bin%c",
            0, user, 0, cygwinized_root, 0);
        pnewenv = newenv;

        std::sprintf(newdir, "%s\\bin", cygwin_root);
        pnewdir = newdir;

        dirsize = GetCurrentDirectory(0, NULL);
        current = (char *)std::malloc(dirsize+4);
        rc = GetCurrentDirectory(dirsize, current);
        if (rc > dirsize)
        {   std::printf("Getting directory failed\n");
            return 1;
        }
        for (i=0; i<dirsize; i++)
            if (current[i] == '\\') current[i] = '/';

        std::sprintf(command,
                "%s\\%s\\cmd /s /d /c %s\\bin\\bash --login -c \\\"cd ",
            std::getenv("WINDIR"), run64 ? "sysnative" : "system32",
            cygwin_root);
        append_command(current);
        std::strcat(command, " ; ");
        for (i=1; i<argc; i++)
        {   append_command(argv[i]);
            if (i != argc-1) std::strcat(command, " ");
        }
        std::strcat(command, "\"");
    }
    rc = CreateProcess(
             NULL,                       // ApplicationName
             command,                    // Command line
             NULL,                       // Process attributes
             NULL,                       // Security attributes
             1,                          // Inherit handles?
             CREATE_NEW_CONSOLE,         // Process creation flags
             pnewenv,                    // environment or NULL
             pnewdir,                    // Current Directory or NULL
             &startup,                   // Startup Info
             &process);                  // process info
    if (rc == 0)
    {   LPTSTR msg = NULL;
        FormatMessage(
            FORMAT_MESSAGE_FROM_SYSTEM |
                FORMAT_MESSAGE_ALLOCATE_BUFFER |
                FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            GetLastError(),
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPTSTR)&msg,
            0,
            NULL);
        if (msg != NULL)
        {   std::fprintf(stderr, "%s\n", msg);
            LocalFree(msg);
            msg = NULL;
        }
        else std::fprintf(stderr, "Process creation failed\n");
        return 1;
    }
// Here I will try to echo the output from the process.
    std::thread echoer(echoOutput, p2a);
    WaitForSingleObject(process.hThread, INFINITE);
    WaitForSingleObject(process.hProcess, INFINITE);
    CloseHandle(p1a);
    CloseHandle(p2b);
    echoer.join();
    CloseHandle(process.hProcess);
    CloseHandle(process.hThread);
    return 0;
}

// end of other-cygwin.cpp
