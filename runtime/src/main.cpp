#include "rasterizer.hpp"

using namespace Rasterizer;

int main()
{

    WindowPtr window = IWindow::Create("Rasterizer", 800, 600);

    while (window->IsOpen())
    {
        window->PollEvents();
        window->Draw();
    }

    return 0;
}
