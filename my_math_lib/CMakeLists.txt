cmake_minimum_required(VERSION 3.5)
project(my_math_lib)

if(NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 99)
endif()
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Wnon-virtual-dtor -Woverloaded-virtual)
endif ()

# 查找依赖文件
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# 添加源文件，生成库
add_library(my_math_lib SHARED
        include/my_math_lib/my_math_lib.hpp
        src/my_math_lib.cpp
        )

# 用于代替传统的target_link_libraries
ament_target_dependencies(my_math_lib
        PUBLIC
        rclcpp
        )

# 添加头文件地址
target_include_directories(my_math_lib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )


# 为了使下游文件可以访问
ament_export_targets(my_math_lib HAS_LIBRARY_TARGET)
ament_export_dependencies(
        rclcpp
)


# 注册 导出头文件
install(
        DIRECTORY include/
        DESTINATION include
)

# 注册 导出库文件
install(
        TARGETS my_math_lib
        EXPORT my_math_lib
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

ament_package()
