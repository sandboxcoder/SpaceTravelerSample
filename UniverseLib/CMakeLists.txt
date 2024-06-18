
cmake_minimum_required(VERSION 3.29.3)

add_library(universe)
target_sources(universe
  PUBLIC
    FILE_SET CXX_MODULES FILES
    universe.cxx
)


