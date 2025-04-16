project(RasterizerCore)

# Create the static library
add_library(rasterizer_core STATIC)

# Add include and source directories
target_include_directories(rasterizer_core PUBLIC include ../shader_module/include)
target_sources(rasterizer_core PRIVATE src/dummy.cpp)
