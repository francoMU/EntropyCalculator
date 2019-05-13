cmake_minimum_required (VERSION 3.2)

project (EntropyCalculator VERSION 0.1 LANGUAGES CXX)


file(GLOB SOURCE src/*.cpp src/*.h)

add_executable(entropy ${SOURCE})

target_include_directories(entropy PUBLIC src/)


# Set compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
target_compile_options(entropy PUBLIC -Wall)

