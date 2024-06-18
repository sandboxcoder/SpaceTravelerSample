
cmake_minimum_required(VERSION 3.29.3)

add_library(universe)
target_sources(universe
  PUBLIC
    FILE_SET cxx_universe_modules TYPE CXX_MODULES 
    FILES
      universe.ixx
)


