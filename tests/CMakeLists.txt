cmake_minimum_required(VERSION 3.16)
project(menu_test)

# Добавление пути до компилятора gcc/g++ 13.1.0
# На gcc/g++ не работает include <format> (так как был добавлен только в 20-м стандарте)
#set(CMAKE_C_COMPILER "/usr/bin/gcc-13")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++-13")
#set(GCOV_EXECUTABLE "/usr/bin/gcov-13")

enable_testing()

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_library(menu_lib ../dialog.h ../dialog.cpp ../internal.h ../internal.cpp)

# Подключение GoogleTest
find_package(GTest REQUIRED)

add_executable(menu_test tests.cpp)
target_link_libraries(menu_test GTest::gtest GTest::gtest_main menu_lib)

add_test(NAME MyTests COMMAND menu_tests)