cmake_minimum_required(VERSION 3.0.0)
project(CPP VERSION 0.1.0)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

set(sources
    main.cpp
    Bitmap.cpp
    FractalCreator.cpp
    RGB.cpp
    Mandelbrot.cpp
    ZoomList.cpp)
add_executable(programa ${sources})
target_link_libraries(programa 
                    gtest
                    gmock
                    pthread)

include(GoogleTest)
gtest_discover_tests(programa)
