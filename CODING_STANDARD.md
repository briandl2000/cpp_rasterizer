# Coding Standard for C++ Software Rasterizer

This document outlines the coding standards and conventions to be followed in the project to ensure consistency, readability, and maintainability.

---

## General Guidelines
1. **Language Standard**: Use **C++17** or later.
2. **File Encoding**: Use UTF-8 encoding for all source files.
3. **Line Endings**: Use LF (`\n`) for line endings.
4. **Indentation**: Use **Tabs** for indentation. Do not use spaces.
5. **Line Length**: Limit lines to **100 characters** where possible.
6. **Comments**: Use `//` for single-line comments and `/* */` for multi-line comments. Write meaningful comments explaining why, not what.

---

## Naming Conventions
1. **Files**:
   - Use `snake_case` for filenames (e.g., `shader_module.cpp`).
   - Header files should have `.hpp` extension, and source files should have `.cpp` extension.

2. **Variables**:
- Use `snake_case` for local variables and function parameters (e.g., `frame_buffer`).
- Use `snake_case` for global variables and constants, prefixed as follows:
    - Prefix constants with `c_` (e.g., `c_frame_time`).
    - Prefix global variables with `g_` (e.g., `g_render_mode`).
    - Prefix static variables with `s_` (e.g., `s_instance_count`).

3. **Functions**:
   - Use `PascalCase` for function names (e.g., `DrawFrame()`).
   - Use descriptive names that clearly indicate the function's purpose.

4. **Classes and Structs**:
   - Use `PascalCase` for class and struct names (e.g., `RasterizerCore`).
   - Prefix interfaces with `I` (e.g., `IShader`).

5. **Macros**:
   - Use `ALL_CAPS` with underscores for macros (e.g., `#define WIDTH 800`).

6. **Namespaces**:
   - Use `PascalCase` for namespace names (e.g., `namespace Rasterizer`).

---

## Code Structure
1. **Header Files**:
   - Use `#pragma once` at the top of all header files.
   - Include only what is necessary. Avoid including unnecessary headers.

2. **Source Files**:
   - Include the corresponding header file first.
   - Group includes in the following order:
     1. Standard library headers.
     2. Third-party library headers.
     3. Project headers.

3. **Functions**:
   - Use `const` wherever applicable for member functions and variables.

4. **Classes**:
   - Use access specifiers (`public`, `protected`, `private`) in the order of decreasing visibility.
   - Group related member variables and functions together.

---

## Error Handling
1. Use exceptions for error handling in critical sections.
2. Use `assert` for debugging and validating assumptions in development builds.
3. Log errors and warnings using a centralized logging mechanism.

---

## Memory Management
1. Prefer smart pointers (`SharedPtr`, `UniquePtr`) over raw pointers.
2. Use `MakeShared` and `MakeUnique` for creating smart pointers.
3. Avoid manual memory management (`new`/`delete`) unless absolutely necessary.

---

## Formatting
1. **Braces**:
   - Use **Allman style** for braces:
     ```cpp
     if (condition)
     {
         // Code
     }
     ```
2. **Spacing**:
   - Place a space after keywords like `if`, `for`, `while`, and `switch`.
   - Do not add spaces inside parentheses.

3. **Empty Lines**:
   - Add empty lines between logical sections of code for readability.

---

## Documentation
1. Use Doxygen-style comments for documenting functions, classes, and methods:
   ```cpp
   /**
    * @brief Draws a frame to the screen.
    * @param frameBuffer The buffer to draw.
    */
   void drawFrame(uint32_t* frameBuffer);
   ```

2. Document all public APIs and complex logic.

---

## Example Code
```cpp
// Example of a well-structured class
#pragma once

#include <cstdint>
#include <vector>

/**
 * @brief Represents a 2D framebuffer.
 */
class FrameBuffer
{
public:
    FrameBuffer(u32 width, u32 height);
    ~FrameBuffer();

    void clear(u32 color);
    u32* getData();

private:
    u32 width;
    u32 height;
    std::vector<u32> data;
};
```

---

By adhering to this coding standard, we ensure that the codebase remains clean, consistent, and easy to maintain.
