cmake_minimum_required(VERSION 3.5)

project(yobotics_sdk C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include/common
		    ${PROJECT_SOURCE_DIR}/include/common/thread
                    ${PROJECT_SOURCE_DIR}/include/robot/Y15/sport
                    ${PROJECT_SOURCE_DIR}/include/robot/channel
                    ${EIGEN3_INCLUDE_DIR}) 

add_executable(Y15_sport_client example/Y15/Y15_sport_client.cpp)

add_executable(Y15_stand_example example/Y15/Y15_stand_example.cpp) 

add_executable(Y15_low_level example/Y15/Y15_low_level.cpp) 

add_executable(Y15_robot_state_client example/Y15/Y15_robot_state_client.cpp) 

find_library(LCM_LIBRARY lcm PATHS /usr/local/lib NO_DEFAULT_PATH)  
  
if(NOT LCM_LIBRARY)
    message(FATAL_ERROR "LCM library not found. Please install LCM.")
else()
    message(STATUS "LCM library found at: ${LCM_LIBRARY}")
endif()

set(COMMON_LIBS
    ${LCM_LIBRARY}
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/libyobotics_sdk.a 
    pthread
)

set(COMMON_LINK_OPTIONS
    -Wl,--start-group
    ${COMMON_LIBS}
    -Wl,--end-group
)

target_link_libraries(Y15_sport_client PRIVATE ${COMMON_LINK_OPTIONS})
target_link_libraries(Y15_stand_example PRIVATE ${COMMON_LINK_OPTIONS})
target_link_libraries(Y15_low_level PRIVATE ${COMMON_LINK_OPTIONS})
target_link_libraries(Y15_robot_state_client PRIVATE ${COMMON_LINK_OPTIONS})

