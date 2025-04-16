#pragma once
#include "Core.h"

namespace Rasterizer
{
    class IWindow;
    using WindowPtr = SharedPtr<IWindow>;

    /**
     * @brief Window interface for platform-specific window management.
     * This interface defines the basic functionality required for creating and managing a window.
     */
    class IWindow
    {
    public:
        IWindow() = default;
        virtual ~IWindow() {};

        static WindowPtr Create(const std::string& title, int width, int height);

        virtual void PollEvents() = 0;
        virtual bool IsOpen() = 0;

        virtual const std::string& GetTitle() = 0;
        virtual int GetWidth() = 0;
        virtual int GetHeight() = 0;
        virtual void* GetWindowHandle() = 0;

        virtual void Draw() = 0;
    };

} // namespace Platform
