
cmake_minimum_required(VERSION 3.29.3)
project ("SpaceTraveler")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Should enable intellisense in Visual Studio
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Include the Universe module.
add_subdirectory ("UniverseLib")

file(GLOB_RECURSE SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cxx" 
    "README.md")

add_executable (SpaceTraveler ${SOURCE_FILES})

target_link_libraries(SpaceTraveler universe)

# Set main as the default project in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SpaceTraveler)
