cmake_minimum_required(VERSION 3.10)
project(My_nums_project)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Установка путей для заголовочных файлов и исходных файлов
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Указание компилятору, где искать заголовочные файлы
include_directories(${INCLUDE_DIR})

# Автоматический поиск всех .cpp файлов в папке src
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

# Создание библиотеки
add_library(lab-3 ${SOURCES})

# Создание исполняемого файла, предположительно main.cpp лежит в корневой директории
add_executable(lab-3_exe main.cpp)

# Линковка библиотеки с исполняемым файлом
target_link_libraries(lab-3_exe PRIVATE lab-3)
