#include <windows.h>
#include <stdio.h>
int main()
{
	SYSTEM_INFO si;
	::GetNativeSystemInfo(&si);

	printf("Number of Logical Processors: %d\n", si.dwNumberOfProcessors);
	printf("Page size: %d Bytes\n", si.dwPageSize);
	printf("Processor Mask: 0x%p\n", (PVOID)si.dwActiveProcessorMask);
	printf("Minimum process address: 0x%p\n", si.lpMinimumApplicationAddress);
	printf("Maximum process address: 0x%p\n", si.lpMaximumApplicationAddress);

	WCHAR buffer[256] = L"";
	DWORD size = sizeof(buffer);
	if (::GetComputerName(buffer, &size))
	{
		printf("ComputerName: %ws\n", buffer);
	}

	WCHAR dir[256] = L"";
	int size_dir = sizeof(dir);
	if (::GetWindowsDirectory(dir, size_dir))
	{
		printf("Windows Path: %ws\n", dir);
	}

	LARGE_INTEGER ticks;
	if (::QueryPerformanceCounter(&ticks))
	{
		printf("QueryPerformanceCounter QuadPart: %d\n", ticks.QuadPart);
		printf("QueryPerformanceCounter HighPart: %d\n", ticks.HighPart);
		printf("QueryPerformanceCounter LowPart: %d\n", ticks.LowPart);

	}

	return 0;
}

