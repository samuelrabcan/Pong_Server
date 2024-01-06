cmake_minimum_required(VERSION 3.18)
project(Pong_SemPraca_Server C)

set(CMAKE_C_STANDARD 99)

add_executable(Pong_SemPraca_Server main.c)
target_link_libraries(Pong_SemPraca_Server pthread)
