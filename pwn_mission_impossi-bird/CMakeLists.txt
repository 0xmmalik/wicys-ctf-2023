cmake_minimum_required(VERSION 3.26)
project(pwn_mission_impossi_bird C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-stack-protector")

add_executable(pwn_mission_impossi_bird main.c)
