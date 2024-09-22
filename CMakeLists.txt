cmake_minimum_required(VERSION 3.16)
project(menu)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)

# Добавление флагов компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

# Добавление пути до компилятора gcc/g++ 13.1.0
# На gcc/g++ не работает include <format> (так как был добавлен только в 20-м стандарте)
#set(CMAKE_C_COMPILER "/usr/bin/gcc-13")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++-13")


# Создание библиотеки из исходных файлов
add_library(menu_lib dialog.h dialog.cpp internal.h internal.cpp)

# Создание исполняемого файла
add_executable(menu main.cpp)

# Линковка исполняемого файла с библиотекой
target_link_libraries(menu menu_lib)
