cmake_minimum_required(VERSION 3.10)
project(detection)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(pxfuncs
    ${CMAKE_CURRENT_SOURCE_DIR}/pxfuncs/pixelfuncs.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pxfuncs/histeq.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pxfuncs/thresholding.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pxfuncs/morpho.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pxfuncs/floodfill.cpp
)
add_executable(detection detection.cpp ${pxfuncs})
target_link_libraries(detection ${OpenCV_LIBS})
