cmake_minimum_required(VERSION 3.15)
project(CppRasterizer)

# Define paths
set(RUNTIME_DIR ${CMAKE_CURRENT_SOURCE_DIR}/runtime)
set(RASTERIZER_CORE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/rasterizer_core)
set(SHADER_MODULE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/shader_module)

# Set C++ standard to 20 globally
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Add WIN32 definition if building on Windows
if (WIN32)
    add_definitions(-DWIN32)
endif()

# Add subdirectories for each project
add_subdirectory(${RUNTIME_DIR})
add_subdirectory(${RASTERIZER_CORE_DIR})
add_subdirectory(${SHADER_MODULE_DIR})
