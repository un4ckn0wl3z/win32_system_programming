#include <windows.h>
#include <stdio.h>
int main()
{
    SYSTEM_INFO si;
    ::GetNativeSystemInfo(&si);

    printf("Number of Logical Processors: %d\n", si.dwNumberOfProcessors);
    printf("Page size: %d Bytes\n", si.dwPageSize);
    
#ifdef _WIN64
    printf("Processor Mask: 0x%016llX\n", si.dwActiveProcessorMask);
#else
    printf("Processor Mask: 0x%08X\n", si.dwActiveProcessorMask);
#endif

    printf("Minimum process address: 0x%p\n", si.lpMinimumApplicationAddress);
    printf("Maximum process address: 0x%p\n", si.lpMaximumApplicationAddress);

    return 0;
}
