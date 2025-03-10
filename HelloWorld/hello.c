#include <windows.h>
#include "beacon.h"

typedef int (WINAPI *MESSAGEBOXA)(HWND, LPCSTR, LPCSTR, UINT);

void go(char *args, int len) {
    HMODULE user32 = LoadLibraryA("user32.dll");
    if (user32 == NULL) {
        BeaconPrintf(CALLBACK_ERROR, "Failed to load user32.dll");
        return;
    }

    MESSAGEBOXA pMessageBoxA = (MESSAGEBOXA)GetProcAddress(user32, "MessageBoxA");
    if (pMessageBoxA == NULL) {
        BeaconPrintf(CALLBACK_ERROR, "Failed to resolve MessageBoxA");
        return;
    }

    pMessageBoxA(NULL, "Hello, World!", "BOF Message", MB_OK | MB_ICONINFORMATION);
    
    FreeLibrary(user32);
}