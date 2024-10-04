# Our C++ project contains a single executable built from main.cpp
# It uses the definitions in my_library.cpp,  which are defined in the header file my_library.h

# Lets compile the library first

# Now we compile the executable
# We need to tell CMake that we want to build an executable
include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(some_library SHARED main.cpp)


add_executable(expression1 main.cpp)