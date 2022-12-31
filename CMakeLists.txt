cmake_minimum_required(VERSION 3.23)
project(stopwatch_and_countdown_timer C)

set(CMAKE_C_STANDARD 23)

add_executable(stopwatch_and_countdown_timer main.c essentials.h countdown.c stopwatch.c)
