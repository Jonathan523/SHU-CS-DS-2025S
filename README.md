# 2024春季数据结构 课程上机作业仓库

## 文件命名
统一放置在`chapter_/_`目录，例如chapter6/1

- 第六章 - 树和森林
- 第七章 - 图
- 第八章 - 查找
- 第九章 - 排序

# 题目描述
请在`main.cpp`中以多行注释的形式在文件头部写明题目，例如
```cpp
/*
    题目：基于图的深度优先搜索策略编写一算法，判别以邻接表方式存储的有向图中是否存在由顶点vi到顶点vj的路径（i!=j）
*/
```

## 目录结构
```
D:\WORKSPACE\C++\SHU-CS-DS-2024S\CHAPTER6
│  CMakeLists.txt // 章节的 CMakeLists
└─10
    │  CMakeLists.txt // 你自己的 CMakeLists
    ├─include  // 头文件
    │      LinkList.hpp  // 后缀用 .hpp
    └─src      // cpp 源文件
            LinkList.cpp
            main.cpp
```

## 编译
统一采用 CMake 编译，需要在自己的目录下创建 `CMakeLists.txt` ,其中至少需要包含以下内容（可以只更改题号）
```cmake
cmake_minimum_required(VERSION 3.10)
project(6.1) # 章节.题目序号
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
```

并在当前章节文件夹下的 `CMakeLists.txt` 中加入 
```cmake
add_subdirectory(目录名称)
```
同时请将编译完成的二进制文件放置于 `/bin/`
可以通过在 `CMakeLists.txt` 中加入
```cmake
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
```
## 环境
本项目在 VS Code 中编辑运行（需要安装 `gcc` `cmake`）

## 提交代码
请**先开新的 branch**
在本地尝试可以正常运行后**发 PR** 以便 code review
不要直接 commit 到 main 分支

