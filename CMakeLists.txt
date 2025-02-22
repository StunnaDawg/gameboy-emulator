cmake_minimum_required(VERSION 3.10)
project(GameBoyEmulator C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Recursively find all .c files in src/
file(GLOB_RECURSE SOURCES "src/*.c")

# Create executable
add_executable(gameboy_emulator ${SOURCES})

# Include all headers in include/ and subdirectories
target_include_directories(gameboy_emulator PRIVATE include)