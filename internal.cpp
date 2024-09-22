#include "internal.h"

namespace menu
{


    /**
     * @brief Функция проверки на наличие в std::map функции с названием exit.
     *
     * 1) В std::map есть функция с таким названием -> выбросить исключение
     * 2) В std::map нет функции с таким названием -> возврат в dialog
     *
     *
     * @param &options - Красно-черное дерево.
     * @return Ничего(пустота).
     */
	void exitCheck(const std::map<const std::string, std::function<void()>> &options)
	{
		std::string wordCheck = "exit";
		for (const auto &[name, function] : options)
		{
			if (wordCheck.find(name) == 0)
			{
                /*это уродство посоветовал мне линтер, но я слышал, что конкатенация по шагам работает быстрее*/
//                std::string error = "There is a function named " + name + " that is similar to exit" + wordCheck;
                std::string error = "There is a function named ";
                error += name;
                error += " that is similar to ";
                error += wordCheck;
				throw std::runtime_error(error);
			}
		}
	}

    /**
     * @brief Функция проверки на наличие в std::map функции с названием help.
     *
     * 1) В std::map есть функция с таким названием -> выбросить исключение
     * 2) В std::map нет функции с таким названием -> возврат в dialog
     *
     *
     * @param &options - Красно-черное дерево.
     * @return Ничего(пустота).
     */
	void helpCheck(const std::map<const std::string, std::function<void()>> &options)
	{
		std::string wordCheck = "help";
		for (const auto &[name, function] : options)
		{
			if (wordCheck.find(name) == 0)
			{
                std::string error = "There is a function named ";
                error += name;
                error += " that is similar to ";
                error += wordCheck;
                throw std::runtime_error(error);
			}
		}
	}

    /**
     * @brief Функция вывода меню в виде "i. Название i-й функции - i-я функция".
     *
     *
     * @param &options - Красно-черное дерево.
     * @return Ничего(пустота).
     */
	void printHelp(const std::map<const std::string, std::function<void()>> &options)
	{
		int count = 1;
		for (const auto &[name, function] : options)
		{
			std::cout << count << ". " << name << std::endl;
			++count;
		}
	}

    /**
     * @brief Функция 1.
     *
     * 1) Выводит, что она функция 1
     *
     * @return Ничего(пустота).
     */
	void option1()
	{
		std::cout << "This is option1" << std::endl;
	}

    /**
     * @brief Функция 2.
     *
     * 1) Выводит, что она функция 2
     *
     * @return Ничего(пустота).
     */
    void option2()
    {
        std::cout << "This is option2" << std::endl;
    }

    /**
     * @brief Функция 3.
     *
     * 1) Выводит, что она функция 3
     *
     * @return Ничего(пустота).
     */
    void option3()
    {
        std::cout << "This is option3" << std::endl;
    }
}
