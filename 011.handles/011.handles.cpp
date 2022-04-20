#include <windows.h>
#include <stdio.h>

bool KillProcess(DWORD pid);

int main()
{
	KillProcess(1234);

	return 0;
}

bool KillProcess(DWORD pid) {
	// open a powerful-enough handle to the process
	HANDLE hProcess = ::OpenProcess(PROCESS_TERMINATE, FALSE, pid);
	if (!hProcess)
		return false;
	// now kill it with some arbitrary exit code
	BOOL success = ::TerminateProcess(hProcess, 1);
	// close the handle
	::CloseHandle(hProcess);
	return success != FALSE;
}




