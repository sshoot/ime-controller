cmake_minimum_required(VERSION 3.10)
project(ime-controller CXX)

add_executable(ime-controller main.cc)
target_link_libraries(ime-controller imm32)
