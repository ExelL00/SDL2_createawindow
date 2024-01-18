cmake_minimum_required(VERSION 3.26)
project(SDL2_createawindow)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
set(SDL2_PATH "D:/Nic i wsyzstko/SDL/SDL2-2.28.4/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories("D:/Nic i wsyzstko/SDL/SDL2_createawindow/Utils")
include_directories("D:/Nic i wsyzstko/SDL/SDL2_createawindow/Shapes")

add_executable(SDL2_createawindow main.cpp
        Graphics/Color.h
        Graphics/Color.cpp
        Graphics/ScreenBuffer.h
        Graphics/ScreenBuffer.cpp
        Graphics/Screen.h
        Utils/Vec2D.cpp
        Utils/Vec2D.h
        Utils/Utils.cpp
        Graphics/Screen.cpp
        Shapes/Line2D.h
        Shapes/Line2D.cpp
        Shapes/Shape.h
        Shapes/Shape.cpp
        Shapes/Tirangle.h
        Shapes/Triangle.cpp
        Shapes/Rectangle.h
        Shapes/Rectangle.cpp
        Shapes/Circle.h
        Shapes/Circle.cpp
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})

