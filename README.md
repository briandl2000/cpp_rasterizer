# C++ Software Rasterizer

This project is a modular, hot-reloadable software rasterizer written in C++. It is designed to simulate a modern GPU pipeline in software, with support for dynamic shader loading, configurable pipelines, and runtime mesh management.

## Features
- **Hot-Reloadable Shaders:** Shaders are implemented as DLLs, allowing live updates without restarting the application.
- **Flexible Pipeline:** Configurable rendering pipelines with dynamic vertex formats and render targets.
- **Platform Abstraction Layer:** Windows-specific platform code is isolated for potential future portability.
- **Runtime Performance Metrics:** Displays frame time and FPS in the application window.
- **Extensible Design:** Modular architecture for easy addition of new features like textures, depth buffers, or advanced shading techniques.

## Project Structure
- `runtime`: Contains the main application and rendering loop.
- `rasterizer_core`: Core library for the rasterizer, including platform abstraction and pipeline management.
- `shader_module`: Shared library for shaders, supporting hot-reloading.
- `include`: Shared headers for cross-module communication.
- `build`: Directory for build artifacts (created during the build process).

## Requirements
- **C++ Compiler:** A modern C++ compiler with support for C++17 or later.
- **CMake:** Version 3.15 or higher.
- **Windows OS:** The platform layer currently supports Windows only.

## Building the Project
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd cpp_rasterizer
   ```

2. Build in Debug mode:
   ```bash
   BuildDebug.bat
   ```

3. Build in Release mode:
   ```bash
   BuildRelease.bat
   ```

4. The executables and DLLs will be located in `build/bin`.

## Running the Application
1. Navigate to the `build/bin` directory.
2. Run the `runtime` executable:
   ```bash
   runtime.exe
   ```

## Shader Development
Shaders are implemented as DLLs in the `shader_module` project. To create or modify shaders:
1. Edit the shader source files in `shader_module/src`.
2. Rebuild the `shader_module` project using CMake.
3. The updated DLL will be hot-reloaded by the runtime application.

## Future Enhancements
- Add support for textures and depth buffers.
- Extend the platform abstraction layer for Linux.
- Implement advanced shading techniques like Phong shading or PBR.

## License
This project is licensed under the MIT License. See `LICENSE` for details.
