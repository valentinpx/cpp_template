cmake_minimum_required(VERSION 2.6)
 
# Project
project(UnitTests)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests tests.cpp)
set(CMAKE_CXX_FLAGS --coverage)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
