cmake_minimum_required(VERSION 2.8.3)
project(test_src)
# %Tag(FULLTEXT)%

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)
add_definitions(-std=c++11)
## Declare ROS messages and services
# add_message_files(FILES Num.msg)
# add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker test_src_generate_messages_cpp)

add_executable(middleman_1 src/1st_middleman.cpp)
target_link_libraries(middleman_1 ${catkin_LIBRARIES})
add_dependencies(middleman_1 test_src_generate_messages_cpp)

add_executable(middleman_2 src/middleman.cpp)
target_link_libraries(middleman_2 ${catkin_LIBRARIES})
add_dependencies(middleman_2 test_src_generate_messages_cpp)

add_executable(middleman_3 src/middleman_3.cpp)
target_link_libraries(middleman_3 ${catkin_LIBRARIES})
add_dependencies(middleman_3 test_src_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener test_src_generate_messages_cpp)

add_executable(listener_2 src/listener_2.cpp)
target_link_libraries(listener_2 ${catkin_LIBRARIES})
add_dependencies(listener_2 test_src_generate_messages_cpp)

add_executable(listener_3 src/listener_3.cpp)
target_link_libraries(listener_3 ${catkin_LIBRARIES})
add_dependencies(listener_3 test_src_generate_messages_cpp)
# %EndTag(FULLTEXT)%
