#include <windows.h>
#include <stdio.h>


int main()
{
    HANDLE hMutex = ::CreateMutex(nullptr, FALSE, TEXT("MyMutex"));


    WCHAR path[MAX_PATH];

    ::GetSystemDirectory(path, MAX_PATH);

    printf("System directory: %ws\n", path);


    return 0;
}

