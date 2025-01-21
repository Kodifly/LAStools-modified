cmake_minimum_required(VERSION 3.10)
project(LAStoolsTest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include LASlib headers
include_directories(/usr/local/include/LASlib)

# Create your executable
add_executable(lasloader lasloader.cpp)
target_link_libraries(lasloader /usr/local/lib/LASlib/libLASlib.a)