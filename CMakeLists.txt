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

set(SourceFiles
    src/Main.cpp
    src/Application.cpp
)

set(IncludeDirs
)

set(ExternalLibs
    spdlog::spdlog
    glfw
)

add_executable(${PROJECT_NAME} ${SourceFiles})
target_include_directories(${PROJECT_NAME} PRIVATE ${IncludeDirs})
target_link_libraries(${PROJECT_NAME} PRIVATE ${ExternalLibs})