project(RasterizerCore)

# Define paths
set(RASTERIZER_CORE_INCLUDE_DIR 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(RASTERIZER_CORE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Create the static library
add_library(rasterizer_core STATIC)

# Add include and source directories
target_include_directories(rasterizer_core PUBLIC ${RASTERIZER_CORE_INCLUDE_DIR} ${SHADER_MODULE_INCLUDE_DIR})
target_sources(rasterizer_core PRIVATE 
    ${RASTERIZER_CORE_SRC_DIR}/platform/platform.cpp
    ${RASTERIZER_CORE_SRC_DIR}/platform/Win32/platform_windows.cpp
)
