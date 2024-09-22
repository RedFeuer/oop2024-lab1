#include "dialog.h"

namespace menu
{
    /**
    * @brief Диалоговая функция.
    *
    * 1) Проверяет, если ли среди функций функция с названием
    * exit или help. Есть -> выкидывает исключение.
    * 2) Пользователь должен ввести строку для обращение к
    * какой-нибудь функции меню.
    * 3) Пользователь ввел help -> выводится меню функций
    * в виде Название функции - Функция
    * Пользователь ввел exit -> выход из функции
    * 4) Проверка на совпадение части названия функции с вводом пользователя
    * Совпало -> функция добавляется в вектор matches
    * 5) В векторе только одно название -> вызов функции с таким названием
    * В векторе нет элементов -> вывод, что функции с таким названием нет
    * В векторе несколько элементов -> вывод, что название функции неточное
    *
    * @param &options - Красно-черное дерево
    * Ключ - строка
    * Значение - функция
    * @return Ничего(void)
    */
	void dialog(const std::map<const std::string, std::function<void()>> &options)
	{
		std::string optionName;
        try {
            /*проверка на то, что в меню нет функции с названием exit*/
            exitCheck(options);
            /*проверка на то, что в меню нет функции с названием help*/
            helpCheck(options);
            while (true) {
                std::string message = "Enter option (or help for menu, exit for quit): ";
                optionName = getStr(message);

                std::string exit = "exit";
                if (exit.find(optionName) == 0) {
                    break;
                }
                std::string help = "help";
                if (help.find(optionName) == 0) {
                    printHelp(options);
                    continue;
                }

                std::vector<std::string> matches; // вектор совпадений названий функций с введенным словом
                /*проход от начала до конца по дереву options и добавление названия опции в
                 * вектор matches при совпадении (описано в теле лямбда-функции)*/
                std::for_each(options.begin(), options.end(), [optionName, &matches] (const auto &pair) {
                    if (pair.first.find(optionName) == 0) {
                        matches.push_back(pair.first);
                    }
                });

                if (matches.size() == 1) {
                    options.at(matches[0])(); // at просто пробегается по всей хэш-таблице
                }
                else if (matches.empty()) {
                    std::cout << "There is no function with name " << optionName << ". Try again" << std::endl;
                }
                else {
                    std::cout << "Ambiguous name of function. Please try again more carefully." << std::endl;
                }
            }
        }
        catch (...) {
            throw;
        }
	}

    /**
     * @brief Диалоговая функция.
     *
     * Эта функция принимает массив структур(название функции - функция) и его размер.
     * 1) Этот массив структур переписывается в контейнер std::map(Красно черное дерево)
     * по правила Название функции - ключ, Функция - значение
     * 2) Вызывается перегруженная функция dialog -
     * void dialog(const std::map<std::string, std::function<void()>> &)
     *
     *
     * @param *options Массив структур.
     * @param size размер массива.
     * @return Ничего(пустота).
     */
    void dialog(const Option *options, int size)
    {
        try {
            std::map<const std::string, std::function<void()>> options_map;
            for (int i = 0; i < size; i++) {
                options_map[options[i].name] = options[i].function;
            }
            dialog(options_map);
        }
        catch (...) {
            throw;
        }
    }

    /**
     * @brief Функция ввода строки.
     *
     * Эта функция принимает сообщение-приглашение пользователя начать ввод(Prompt)
     * и возвращает считанную с входного потока строку (ввод в консоли).
     *
     * 1) Выводится сообщение-приглашение
     * 2) Чтение строки
     * 3) Встречен EOF (Unix: Ctrl + D, Windows: Ctrl + Z) -> выкидывает исключение
     * 4) Встречен failbit -> выкидывает исключение
     * 5) Встречена пустая строка -> все начинается заново
     * 6) Успешный ввод -> возврат строки
     *
     *
     *
     * @param &message Prompt - сообщение-приглашения пользователя
     * @return std::string - считанная с входного потока(Console INput) строка.
     */
    std::string getStr(const std::string &message) {
        while (true) {
            std::cout << message << std::endl;
            std::string input;
            std::getline(std::cin, input);
            if (std::cin.eof()) {
                throw std::runtime_error("Failed to read string: EOF");
            }
            if (std::cin.fail()){
                throw std::runtime_error("Failed to read string");
            }
            if (input.empty()) {
                continue;
            }
            return input;
        }
    }
}
