#include <windows.h>
#include <cstdint>
#include <corecrt_math.h>
#include <string> // For std::to_string
#include <chrono> // For frame timing

// global
#define WIDTH 800
#define HEIGHT 600
uint32_t* framebuffer = new uint32_t[WIDTH * HEIGHT]; // BGRA32 (Windows native)
BITMAPINFO bmi = {};
float frameTime = 0.0f;
float fps = 0.0f;

// Add a function to draw text on the screen
void DrawTextOnScreen(HDC hdc, const char* text, int x, int y)
{
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(255, 255, 255)); // White text
    TextOut(hdc, x, y, text, lstrlen(text));
}

// Window Procedure function
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
    {
        HDC hdc = GetDC(hwnd); // or use BeginPaint/EndPaint if inside WM_PAINT
        StretchDIBits(hdc,
            0, 0, WIDTH, HEIGHT,
            0, 0, WIDTH, HEIGHT,
            framebuffer, &bmi, DIB_RGB_COLORS, SRCCOPY);

        // Draw the ms/frame and FPS text
        static char frameTimeText[64];
        snprintf(frameTimeText, sizeof(frameTimeText), "ms/frame: %.2f | FPS: %.2f", frameTime, fps);
        DrawTextOnScreen(hdc, frameTimeText, 10, 10);

        ReleaseDC(hwnd, hdc);
    }
    break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int main()
{
    // Define the window class
    const char CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    // Register the window class
    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindowEx(
        0,                            // Optional window styles
        CLASS_NAME,                   // Window class
        "Sample Window",             // Window title
        WS_OVERLAPPEDWINDOW,          // Window style
        CW_USEDEFAULT, CW_USEDEFAULT, // Position
        WIDTH, HEIGHT, // Size
        NULL,                         // Parent window
        NULL,                         // Menu
        GetModuleHandle(NULL),        // Instance handle
        NULL                          // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    // Show the window
    ShowWindow(hwnd, SW_SHOW);

    // Run the message loop
    MSG msg = {};

    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = WIDTH;
    bmi.bmiHeader.biHeight = -HEIGHT; // Negative to flip Y so it's top-down
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB; // no compression

    float time = 0.0f;
    auto lastFrameTime = std::chrono::high_resolution_clock::now();
    auto fpsStartTime = lastFrameTime;
    int frameCount = 0;

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        // Calculate frame time
        auto currentFrameTime = std::chrono::high_resolution_clock::now();
        frameTime = std::chrono::duration<float, std::milli>(currentFrameTime - lastFrameTime).count();
        lastFrameTime = currentFrameTime;

        // Calculate FPS
        frameCount++;
        auto elapsedTime = std::chrono::duration<float>(currentFrameTime - fpsStartTime).count();
        if (elapsedTime >= 1.0f)
        {
            fps = frameCount / elapsedTime;
            frameCount = 0;
            fpsStartTime = currentFrameTime;
        }

        time += 1.f / 60.f;
        float s = sin(time) * .5f + .5f;
        uint8_t color = static_cast<uint8_t>(s * 255);
        uint8_t a = 0;
        uint8_t r = color;
        uint8_t g = 255;
        uint8_t b = 0;
        for (int y = 0; y < HEIGHT; ++y)
        {
            for (int x = 0; x < WIDTH; ++x)
            {
                framebuffer[y * WIDTH + x] = (a << 24) | (r << 16) | (g << 8) | b; // RGB set to the same value
            }
        }
    }

    return 0;
}
