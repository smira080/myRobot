cmake_minimum_required(VERSION 3.20)
project(UnitTests)

# Add GoogleTest properly with an explicit binary directory
ADD_SUBDIRECTORY(../lib/googletest build/googletest)

add_executable(runAllTests
    test_main.cpp
    ../src/Motor.cpp
    ../src/Pot.cpp
    ../src/led.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main pthread)
