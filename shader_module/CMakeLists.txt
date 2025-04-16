project(ShaderModule)

# Create the shared library (DLL)
add_library(shader_module SHARED)

# Add include and source directories
target_include_directories(shader_module PUBLIC include)
target_sources(shader_module PRIVATE src/dummy.cpp)

# Set the output directory for the shader module DLL
set_target_properties(shader_module PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin
)
