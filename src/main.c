#include <windows.h>

int CALLBACK WinMain(HINSTANCE h_instance,
                     HINSTANCE h_prev_instance,
                     LPSTR lp_cmd_line,
                     int n_cmd_show)
{
    MessageBoxA(0, "this is handmade hero.", "handmade-hero", MB_OK|MB_ICONINFORMATION);
    return 0;
}