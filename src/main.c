#include <windows.h>

LRESULT CALLBACK
main_window_cb(HWND window,
               UINT msg,
               WPARAM w_param,
               LPARAM l_param)
{
    LRESULT result = 0;

    switch (msg) {
        case WM_SIZE:
        {
            OutputDebugStringA("WM_SIZE\n");
        } break;
        case WM_DESTROY:
        {
            OutputDebugStringA("WM_DESTROY\n");
        } break;
        case WM_CLOSE:
        {
            OutputDebugStringA("WM_CLOSE\n");
        } break;
        case WM_ACTIVATEAPP:
        {
            OutputDebugStringA("WM_ACTIVATEAPP\n");
        } break;
        case WM_PAINT:
        {
            PAINTSTRUCT paint;
            HDC device_ctx = BeginPaint(window, &paint);
            LONG x = paint.rcPaint.left;
            LONG y = paint.rcPaint.top;
            LONG width = paint.rcPaint.right - paint.rcPaint.left;
            LONG height = paint.rcPaint.bottom - paint.rcPaint.top;
            PatBlt(device_ctx, x, y, width, height, WHITENESS);
            EndPaint(window, &paint);
        } break;
        default:
        {
            result = DefWindowProc(window, msg, w_param, l_param);
        } break;
    }

    return result;
}

int CALLBACK
WinMain(HINSTANCE instance,
        HINSTANCE prev_instance,
        LPSTR cmd_line,
        int show_code)
{
    WNDCLASS window_class = {0};
    window_class.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
    window_class.lpfnWndProc = main_window_cb;
    window_class.hInstance = instance;
    window_class.lpszClassName = "HandmadeHeroWindowClass";

    if (RegisterClass(&window_class)) {
        HWND window_handle = CreateWindowEx(0,
                                            window_class.lpszClassName,
                                            "handmade-hero",
                                            WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                                            CW_USEDEFAULT,
                                            CW_USEDEFAULT,
                                            CW_USEDEFAULT,
                                            CW_USEDEFAULT,
                                            0,
                                            0,
                                            instance,
                                            0);
        if (window_handle) {
            while (1) {
                MSG msg;
                BOOL msg_result = GetMessage(&msg, 0, 0, 0);
                if (msg_result <= 0)
                    break;
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        } else {
            // TODO: logging
        }
    } else {
	    // TODO: logging
    }

    return 0;
}