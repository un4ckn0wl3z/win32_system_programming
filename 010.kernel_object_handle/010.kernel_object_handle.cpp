#include <windows.h>
#include <stdio.h>

void NotifyOtherInstance();

int main()
{
	HANDLE hMutex = ::CreateMutex(nullptr, FALSE, L"SingleInstanceMutex");
	if (!hMutex) 
	{
		printf("Failed to create mutex (Error: %d)\n", ::GetLastError());
	}

	if (::GetLastError() == ERROR_ALREADY_EXISTS) {
		printf("Process already created\n");
	}
	else {
		system("pause");
	}

	

	return 0;
}



