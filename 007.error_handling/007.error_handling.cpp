#include <windows.h>
#include <stdio.h>
int main()
{
    
    BOOL success = FALSE;
    if (!success) {
        // error - handle it (just print it in this example)
        printf("Error: %d\n", ::GetLastError());
    }

    return 0;
}
