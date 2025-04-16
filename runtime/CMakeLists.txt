project(Runtime)

# Create the executable
add_executable(runtime src/main.cpp)

# Include the rasterizer_core and shader_module headers
target_include_directories(runtime PRIVATE ../rasterizer_core/include ../shader_module/include)

# Link the rasterizer_core library
target_link_libraries(runtime PRIVATE rasterizer_core shader_module)

# Set the output directory for the runtime executable
set_target_properties(runtime PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin
)
