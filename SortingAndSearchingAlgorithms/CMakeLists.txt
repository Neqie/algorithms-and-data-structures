cmake_minimum_required(VERSION 3.10)

# Указываем язык C++ (так как файл main.cpp)
project(SortingAlgorithms CXX)

# Стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем исполняемый файл sorter из main.cpp
add_executable(sorter main.cpp)