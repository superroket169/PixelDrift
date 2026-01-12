cmake_minimum_required(VERSION 3.10)
project(PixelDrift)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_ROOT "/home/isa/Documents/Codes/SFML/build-mingw/sfml-install")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIBRARY_DIR "${SFML_ROOT}/lib")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_definitions(-DSFML_STATIC)

include_directories(${SFML_INCLUDE_DIR})

add_executable(main main.cpp)

target_link_libraries(main 
    ${SFML_LIBRARY_DIR}/libsfml-graphics-s.a
    ${SFML_LIBRARY_DIR}/libsfml-window-s.a
    ${SFML_LIBRARY_DIR}/libsfml-system-s.a
    ${SFML_LIBRARY_DIR}/libfreetype.a
    
    opengl32
    winmm
    gdi32
    
    -static-libgcc
    -static-libstdc++
    -static
    -lpthread
)