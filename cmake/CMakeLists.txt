cmake_minimum_required(VERSION 3.29.2)

project(sdl)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(
    ../includes
    ${SDL2_INCLUDE_DIRS}
)

file(GLOB SRC_FILES ../src/*)

add_executable(
    ${PROJECT_NAME}
    ../main.cpp
    ${SRC_FILES}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES DEBUG_POSTFIX _debug
)