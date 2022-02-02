cmake_minimum_required(VERSION 3.10)
project(unit_1)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(funcs
    ${CMAKE_CURRENT_SOURCE_DIR}/functions/histeq.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/functions/histeq.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/functions/floodfill.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/functions/floodfill.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/functions/erosion.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/functions/erosion.hpp
)
add_executable(unit_1 unit_1.cpp ${funcs})
target_link_libraries(unit_1 ${OpenCV_LIBS})