# Space Traveler

Sample project (C++ 23) that utilizes C++ modules with CMake for Visual Studio.  
Currently, this project is simply creating a Galaxy of planets (in code).

## Building this Project
In order to build you will need to download CMake (at least 3.29.3) to build the solution.  

Below is the following command I used to generate the solution on Windows (note for Linux/Unix, use "Unix Makefiles"):

```
mkdir build
cd build
cmake -G "Visual Studio 17 2022" ..

```

## Implementation notes

Modules are defined within .ixx files as required by Visual Studio (otherwise Intellisense will not work). Also, we set the CMAKE_CXX_SCAN_FOR_MODULES flag.