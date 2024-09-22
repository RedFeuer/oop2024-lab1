#ifndef INTERNAL_H
#define INTERNAL_H

#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <string>
#include <algorithm>
#include <cstring>
#include <limits>
#include <format>

namespace menu
{
    /**
    * @brief Тип функции обратного вызова.
    *
    * typedef определяет функцию обратного вызова без параметров и возвращаемого значения.
    */
    typedef void (*CallbackFunction)();

     /**
     * @brief Структура для опции с именем и функцией обратного вызова.
     *
     * Структура содержит имя опции и соответствующую функцию обратного вызова.
     */
    struct Option
    {
        /**
         * @brief Имя опции.
         *
         * Это указатель на массив символов, представляющий имя опции.
         */
        char *name;

        /**
         * @brief Функция обратного вызова.
         *
         * Указатель на функцию обратного вызова, которая будет выполнена при выборе данной опции.
         */
        CallbackFunction function;
    };

	void exitCheck(const std::map<const std::string, std::function<void()>> &);

	void helpCheck(const std::map<const std::string, std::function<void()>> &);

	void printHelp(const std::map<const std::string, std::function<void()>> &);

	void option1();
	void option2();
	void option3();
}

#endif