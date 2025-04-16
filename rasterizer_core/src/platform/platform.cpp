#include "platform/platform.hpp"

#ifdef WIN32
#include "platform/Win32/platform_windows.hpp"
#endif

namespace Rasterizer
{

    WindowPtr IWindow::Create(const std::string& title, int width, int height)
    {
#ifdef WIN32
        return MakeShared<Windows::Window>(title, width, height);
#else
        // TODO: error handling
        return nullptr;
#endif
    }

}