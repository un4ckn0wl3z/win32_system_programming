#include <windows.h>
#include <stdio.h>
#include <strsafe.h>

void wmain(int argc, const wchar_t* argv[])
{
	WCHAR buffer[32];
	WCHAR* buffer2 = (WCHAR*)malloc(32 * sizeof(WCHAR));


	StringCchCopy(buffer, _countof(buffer), argv[1]);
	StringCchCat(buffer, _countof(buffer), L"cat");
	StringCchCopy(buffer2, 32, argv[1]);
	StringCchCat(buffer2, 32, L"cat");

	free(buffer2);
}


