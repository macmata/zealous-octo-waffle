cmake_minimum_required (VERSION 3.0)
project (zealous-octo-waffle)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")

add_definitions(-DMG_ENABLE_THREADS)

add_executable(server
        src/main.cpp
        src/server/server.cpp
        mongoose-6.0/mongoose.c)

