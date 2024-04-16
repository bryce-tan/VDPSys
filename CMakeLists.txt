cmake_minimum_required(VERSION 3.14)
project(CloudDiskSystem)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Add include directory
include_directories(include)

# Add the executable
add_executable(${PROJECT_NAME} main.cpp src/request_queue.cpp src/placer.cpp src/monitor.cpp src/warehouse.cpp)
