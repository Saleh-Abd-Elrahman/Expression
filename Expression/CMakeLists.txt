# Every CMake project needs to start with these two lines
cmake_minimum_required(VERSION 3.20) # This is the minimum version of CMake required
project(MyVeryCoolProject VERSION 1.0) # This is the name of the project and its versino
set(PROJECT_AUTHOR "Saleh Abd Elrahman")

set(CMAKE_CXX_STANDARD 17) # This sets the C++ standard to C++17
set(CMAKE_CXX_STANDARD_REQUIRED True) # This tells CMake that the stdandard must be available

# We place the executables in the bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# We place the libraries in the lib directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Enable Testing
enable_testing()

# Include directories
include_directories(include)

# Add Subdirectories
add_subdirectory(homework)
add_subdirectory(tests)
add_subdirectory(docs)  