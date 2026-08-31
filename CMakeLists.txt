cmake_minimum_required(VERSION 3.21)

# Build External Libraries
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_INSTALL OFF CACHE INTERNAL "")

add_subdirectory(external/glfw)

add_subdirectory(external/spdlog)

# Build Magika
project(Magika VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Vulkan REQUIRED)

set(SourceFiles
    src/Main.cpp
    src/Application.cpp
    src/Window/WindowManager.cpp
    src/Logging/LoggingManager.cpp
)

set(IncludeDirs
)

set(ExternalLibs
    spdlog::spdlog
    glfw
    Vulkan::Vulkan
)

add_executable(${PROJECT_NAME} ${SourceFiles})
target_include_directories(${PROJECT_NAME} PRIVATE ${IncludeDirs})
target_link_libraries(${PROJECT_NAME} PRIVATE ${ExternalLibs})

# Set define for Debug build
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Configuring for a Debug build")
    target_compile_definitions(${PROJECT_NAME} PUBLIC "MK_DEBUG")
endif()

# Auto-generate Version.h
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Version.hpp.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Version.hpp"
    @ONLY
)