cmake_minimum_required(VERSION 3.15)
# 项目名称
project(LibraryManagementSystem)
# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # 关闭编译器扩展，严格C++17

# =====================================
# 头文件目录
# =====================================
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/entity
    ${PROJECT_SOURCE_DIR}/include/repository
    ${PROJECT_SOURCE_DIR}/include/service
    ${PROJECT_SOURCE_DIR}/include/controller
    ${PROJECT_SOURCE_DIR}/include/view
    ${PROJECT_SOURCE_DIR}/include/utils
)

# =====================================
# 自动搜索src下所有cpp文件
# =====================================
file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# =====================================
# 生成可执行文件
# =====================================
add_executable(
    LibraryManagementSystem
    ${SOURCES}
)

if(MSVC)
    add_compile_options(/utf-8)
endif()

# =====================================
# 数据文件复制
# 运行程序时可以访问data目录
# =====================================
file(COPY
    ${PROJECT_SOURCE_DIR}/data
    DESTINATION
    ${CMAKE_BINARY_DIR}
)

