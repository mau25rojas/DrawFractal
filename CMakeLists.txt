cmake_minimum_required(VERSION 3.0.0)
project(CPP VERSION 0.1.0)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Set include directory for header files
include_directories("include") #API header files included via parent CMake

set(CMAKE_CXX_STANDARD 11)

set(sources
    src/main.cpp
    src/Bitmap.cpp
    src/FractalCreator.cpp
    src/RGB.cpp
    src/Mandelbrot.cpp
    src/ZoomList.cpp)

add_executable(DrawFractal ${sources})

target_link_libraries(DrawFractal 
                    #gtest
                    #gmock
                    pthread)
