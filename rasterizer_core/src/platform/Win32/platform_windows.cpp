#ifdef WIN32
#include "platform/Win32/platform_windows.hpp"
#include "platform_windows.hpp"

namespace Rasterizer::Windows
{

    // Window Procedure function
    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }

    Window::Window(const std::string& title, int width, int height)
        : m_title(title), m_width(width), m_height(height)
    {
        // Define the window class
        const char CLASS_NAME[] = "Window Class";

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
            m_title.c_str(),              // Window title
            WS_OVERLAPPEDWINDOW,          // Window style
            CW_USEDEFAULT, CW_USEDEFAULT, // Position
            m_width, m_height,            // Size
            NULL,                         // Parent window
            NULL,                         // Menu
            GetModuleHandle(NULL),        // Instance handle
            NULL                          // Additional application data
        );

        if (hwnd == NULL)
        {
            // Handle error
        }

        // Show the window
        ShowWindow(hwnd, SW_SHOW);

        m_window_handle.handle = hwnd;
        m_is_open = (m_window_handle.handle != nullptr);

        m_framebuffer.resize(m_width * m_height, 0xFF0000FF); // Initialize framebuffer with zeros

        m_bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        m_bmi.bmiHeader.biWidth = m_width;
        m_bmi.bmiHeader.biHeight = -m_height; // Negative to flip Y so it's top-down
        m_bmi.bmiHeader.biPlanes = 1;
        m_bmi.bmiHeader.biBitCount = 32;
        m_bmi.bmiHeader.biCompression = BI_RGB; // no compression
    }

    Window::~Window()
    {
        if (m_window_handle.handle)
        {
            DestroyWindow(static_cast<HWND>(m_window_handle.handle));
        }
    }

    void Rasterizer::Windows::Window::PollEvents()
    {
        MSG msg;
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                m_is_open = false;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    bool Window::IsOpen()
    {
        return m_is_open;
    }

    const std::string &Window::GetTitle()
    {
        return m_title;
    }

    int Window::GetWidth()
    {
        return m_width;
    }

    int Window::GetHeight()
    {
        return m_height;
    }

    void* Window::GetWindowHandle()
    {
        return &m_window_handle;
    }

    void Window::Draw()
    {
        HDC hdc = GetDC(m_window_handle.handle);
        StretchDIBits(hdc,
            0, 0, m_width, m_height,
            0, 0, m_width, m_height,
            m_framebuffer.data(), &m_bmi, DIB_RGB_COLORS, SRCCOPY);

        ReleaseDC(m_window_handle.handle, hdc);
    }
}

#endif // WIN32