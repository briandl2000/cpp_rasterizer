project(ShaderModule)

# Define paths
set(SHADER_MODULE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SHADER_MODULE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(RASTERIZER_CORE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../rasterizer_core/include)

# Create the shared library (DLL)
add_library(shader_module SHARED)

# Add include and source directories
target_include_directories(shader_module PUBLIC ${SHADER_MODULE_INCLUDE_DIR} ${RASTERIZER_CORE_INCLUDE_DIR})
target_sources(shader_module PRIVATE ${SHADER_MODULE_SRC_DIR}/dummy.cpp)

# Link against rasterizer_core
target_link_libraries(shader_module PRIVATE rasterizer_core)

# Set the output directory for the shader module DLL
set_target_properties(shader_module PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin
)
