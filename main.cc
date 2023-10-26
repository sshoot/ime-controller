#include <iostream>
#include <windows.h>
#include <imm.h>

// status = 0: IME is disabled
// status = 1: IME is enabled

int getInputMethod(HWND imeHwnd) {
    int status;

    status = SendMessage(imeHwnd, WM_IME_CONTROL, 0x0005, 0);
    return status;
}

int switchInputMethod(HWND imeHwnd, int status) {
    SendMessage(imeHwnd, WM_IME_CONTROL, 0x0006, status);
    return 0;
}

int main(int argc, char** argv) {
    HWND hwnd, imeHwnd;

    hwnd = GetForegroundWindow();
    imeHwnd = ImmGetDefaultIMEWnd(hwnd);
    if (argc == 1) {
        int status = getInputMethod(imeHwnd);
        std::cout << std::dec << status << std::endl;
    } else {
        int status = atoi(argv[1]);
        switchInputMethod(imeHwnd, status);
    }
    return 0;
}
