cmake_minimum_required(VERSION 3.5)
project(complex_test)

#=========================== 常规的编译器设置===============================================
if(NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 99)
endif()
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Wnon-virtual-dtor -Woverloaded-virtual)
endif ()
#========================================================================================

#set(CMAKE_PREFIX_PATH ../../install)

find_package(ament_cmake REQUIRED)
find_package(my_math_lib REQUIRED)
find_package(rclcpp REQUIRED)


# 查找依赖文件
add_executable(complex_test
        src/complex_test.cpp
        )

ament_target_dependencies(complex_test
        my_math_lib
        rclcpp
        )

install(TARGETS complex_test
        DESTINATION lib/${PROJECT_NAME})

ament_package()
