cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_CXX_CPPLINT "cpplint;--filter=-legal/copyright,-build/include")

file(GLOB app_src "*.cpp")
add_executable(tdd_taxi_cpp ${app_src})
