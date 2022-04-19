#include <windows.h>
#include <stdio.h>

void wmain(int argc, const wchar_t* argv[]) 
{
	WCHAR buffer[32];
	wcscpy_s(buffer, argv[1]);

	WCHAR* buffer2 = (WCHAR*)malloc(32 * sizeof(WCHAR));
	//wcscpy_s(buffer2, argv[1]); // does not compile
	wcscpy_s(buffer2, 32, argv[1]); // size in characters (not bytes)
	free(buffer2);

}


