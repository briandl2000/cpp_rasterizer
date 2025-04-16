project(Runtime)

# Define paths
set(RUNTIME_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(RASTERIZER_CORE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../rasterizer_core/include)
set(SHADER_MODULE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../shader_module/include)

# Create the executable
add_executable(runtime ${RUNTIME_SRC_DIR}/main.cpp)

# Include the rasterizer_core and shader_module headers
target_include_directories(runtime PRIVATE ${RASTERIZER_CORE_INCLUDE_DIR} ${SHADER_MODULE_INCLUDE_DIR})

# Link the rasterizer_core library
target_link_libraries(runtime PRIVATE rasterizer_core shader_module)

# Set the output directory for the runtime executable
set_target_properties(runtime PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin
)
