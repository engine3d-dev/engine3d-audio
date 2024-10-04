cmake_minimum_required(VERSION 3.25)
project(engine3d-audio LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works (in creating the compile_commands.json file)


# find_package(OpenAL REQUIRED)
# find_package(gstreamer REQUIRED)
add_subdirectory(demo)
add_subdirectory(src)

# Copy to source directory
add_custom_target(
    copy-compile-commands ALL
    DEPENDS
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_LIST_DIR}/compile_commands.json
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_CURRENT_LIST_DIR}/compile_commands.json
    DEPENDS
    # Unlike "proper" targets like executables and libraries, 
    # custom command / target pairs will not set up source
    # file dependencies, so we need to list file explicitly here
    generate-compile-commands
    ${CMAKE_BINARY_DIR}/compile_commands.json
)

# Generate the compilation commands. Necessary so cmake knows where it came
# from and if for some reason you delete it.
add_custom_target(generate-compile-commands
    DEPENDS
        ${CMAKE_BINARY_DIR}/compile_commands.json
)

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/compile_commands.json
    COMMAND ${CMAKE_COMMAND} -B${CMAKE_BINARY_DIR} -S${CMAKE_SOURCE_DIR}
)

# target_include_directories(${PROJECT_NAME} PRIVATE audio/internal)
# target_include_directories(${PROJECT_NAME} PUBLIC ./ ./audio audio/internal)
target_include_directories(${PROJECT_NAME} PUBLIC ./)
target_include_directories(${PROJECT_NAME} PRIVATE audio audio/internal)

# target_link_libraries(${PROJECT_NAME} PRIVATE
#     gstreamer::gstreamer-1.0 gstreamer::gstreamer-base-1.0 gstreamer::gstreamer-controller-1.0
#     gstreamer::gstreamer-net-1.0 gstreamer::gstreamer-check-1.0)
# if (TARGET gstreamer::gstcoreelements)
#     target_link_libraries(${PROJECT_NAME} PRIVATE gstreamer::gstcoreelements)
# endif ()