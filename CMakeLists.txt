cmake_minimum_required(VERSION 3.9)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googlemock)
add_executable(testcode main.cpp)
add_executable(128.solution 128.\ Longest\ Consecutive\ Sequence/solution.cpp)
add_executable(139.solution 139.\ Word\ Break/solution.cpp)

target_link_libraries(128.solution gmock)
target_link_libraries(139.solution gmock)
