#define BUILD_WINDOWS
#include <windows.h>
#include <stdio.h>
#include <versionhelpers.h>
int main()
{

    OSVERSIONINFO vi = { sizeof(vi) }; // deprecated method
    ::GetVersionEx(&vi);

    printf("Version: %d.%d.%d\n",
        vi.dwMajorVersion, vi.dwMinorVersion, vi.dwBuildNumber);

    if (IsWindowsXPOrGreater()) {
        printf("IsWindowsXPOrGreater is TRUE\n");
    }

    if (IsWindowsXPSP3OrGreater()) {
        printf("IsWindowsXPSP3OrGreater is TRUE\n");

    }

    if (IsWindows7OrGreater()) {
        printf("IsWindows7OrGreater is TRUE\n");

    }

    if (IsWindows8Point1OrGreater()) {
        printf("IsWindows8Point1OrGreater is TRUE\n");

    }

    if (IsWindows10OrGreater()) {
        printf("IsWindows10OrGreater is TRUE\n");

    }

    if (IsWindowsServer()) {
        printf("IsWindowsServer is TRUE\n");

    }



    return 0;
}
