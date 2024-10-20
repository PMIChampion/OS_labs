cmake_minimum_required(VERSION 3.10)
project(LabProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(child src/child.cpp)
target_include_directories(child PRIVATE include)

add_executable(lab-1 main.cpp src/parent.cpp src/utils.cpp)
target_include_directories(lab-1 PRIVATE include)

add_dependencies(lab-1 child)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(run_tests tests/tests.cpp src/parent.cpp src/utils.cpp)
target_include_directories(run_tests PRIVATE include)

target_link_libraries(run_tests PRIVATE GTest::gtest_main pthread)

add_test(NAME Lab1Tests COMMAND run_tests)
