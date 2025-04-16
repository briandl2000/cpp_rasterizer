cmake_minimum_required(VERSION 3.15)
project(CppRasterizer)

# Define paths
set(RUNTIME_DIR ${CMAKE_CURRENT_SOURCE_DIR}/runtime)
set(RASTERIZER_CORE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/rasterizer_core)
set(SHADER_MODULE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/shader_module)

# Add subdirectories for each project
add_subdirectory(${RUNTIME_DIR})
add_subdirectory(${RASTERIZER_CORE_DIR})
add_subdirectory(${SHADER_MODULE_DIR})
