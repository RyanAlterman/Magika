cmake_minimum_required(VERSION 3.21)

project(Magika VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SourceFiles
    src/Main.cpp
)

set(IncludeDirs
)

set(ExternalLibs
)

add_executable(${PROJECT_NAME} ${SourceFiles})
target_include_directories(${PROJECT_NAME} PRIVATE ${IncludeDirs})
target_link_libraries(${PROJECT_NAME} PRIVATE ${ExternalLibs})