#include <Windows.h>
#include <stdlib.h>

int main(void) {
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) {
        ShowWindow(hwnd, SW_HIDE);
        DeleteObject(hwnd);
    }
    Sleep(5000);
    HDC hdc = GetDC(NULL);
    if (hdc == NULL) return 0;
    HBRUSH hbr = CreateSolidBrush(RGB(255, 0, 255));
    if (hbr != NULL) {
        RECT lprc = { 0, 0, 0, 0 };
        for (int i = 0; i < 1000; ++i) {
            int h = rand() % (1001 - (i-500)*(i-500)/250) + 1;
            int x = rand() % 1920;
            lprc.left = x;
            lprc.right = x+1;
            for (int j = 1; j <= h; ++j) {
                lprc.bottom = j;
                FillRect(hdc, &lprc, hbr);
            }
            Sleep((i-500)*(i-500)/125);
        }
        DeleteObject(hbr);
    }
    ReleaseDC(NULL, hdc);
    return 0;
}
