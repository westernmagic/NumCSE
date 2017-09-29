cmake_minimum_required (VERSION 3.2.2)

project ("series0")

include ("../common/cmake/Common.cmake")

add_executable (factorial factorial.cpp)
target_link_libraries (factorial Backward::Backward)

add_executable (fractal fractal.cpp)
target_link_libraries (fractal Backward::Backward MathGL2::MathGL2)
