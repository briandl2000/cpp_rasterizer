#ifdef WIN32
#pragma once
#include "platform/platform.hpp"
#include <vector>

namespace Rasterizer::Windows
{
    
    struct WindowHandle
    {
        HWND handle {nullptr};
    };

    class Window : public IWindow
    {
    public:
        Window(const std::string& title, int width, int height);
        ~Window() override;

        virtual void PollEvents() override;
        virtual bool IsOpen() override;

        virtual const std::string& GetTitle() override;
        virtual int GetWidth() override;
        virtual int GetHeight() override;
        virtual void* GetWindowHandle() override;
        virtual void Draw();
    private:

    private:
        const std::string& m_title {""};
        int m_width {0};
        int m_height {0};
        bool m_is_open {false};
        WindowHandle m_window_handle {};

        std::vector<u32> m_framebuffer {};
        BITMAPINFO m_bmi = {};
    };

}
#endif // WIN32