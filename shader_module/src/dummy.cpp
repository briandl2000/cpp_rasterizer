#include <iostream>

extern "C" __declspec(dllexport) void helloShader() {
    std::cout << "Hello Shader!" << std::endl;
}
