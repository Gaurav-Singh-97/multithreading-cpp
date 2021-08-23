cmake_minimum_required(VERSION 3.21.0)	#using my current version as min
project (ProducerConsumerProblem)
set (CMAKE_CXX_FLAGS "-std=c++11 -g")
add_executable(producerconsumer main.cpp)
target_link_libraries(producerconsumer pthread)
