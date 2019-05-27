cmake_minimum_required (VERSION 3.4)

project (EntropyCalculator VERSION 0.1 LANGUAGES CXX)


file(GLOB SOURCE src/*.cpp src/*.h)

add_executable(entropy ${SOURCE})

target_include_directories(entropy PUBLIC src/)

set_target_properties(entropy PROPERTIES CXX_STANDARD 11 
  CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

target_compile_options(entropy PUBLIC -Wall -std=c++11)

