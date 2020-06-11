cmake_minimum_required(VERSION 3.0.0)
project(tdd_taxi_cpp VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(unit_test)
