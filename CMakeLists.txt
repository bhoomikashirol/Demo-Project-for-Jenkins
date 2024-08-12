cmake_minimum_required(VERSION 3.10)

# Set the project name
project(DemoProject)

# Add the main executable
add_executable(DemoProject Code.cpp)

# Enable testing
enable_testing()

# Find and include GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(runTests CodeTest.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Add a test
add_test(NAME DemoTest COMMAND runTests)

