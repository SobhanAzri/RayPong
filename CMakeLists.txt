cmake_minimum_required(VERSION 3.23)

project(RayPong VERSION 0.1 LANGUAGES CXX)

add_executable(RayPong
        src/raypong.cpp
        src/Ball/ball.cpp
        src/Boards/board.cpp
        src/Boards/playerBoard.cpp
        src/Boards/cpuBoard.cpp
)

target_include_directories(RayPong PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


target_link_libraries(RayPong
    PRIVATE
        raylib
)
