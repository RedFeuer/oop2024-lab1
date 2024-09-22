#include "dialog.h"


/**
     * @brief Функция main.
     *
     * Эта функция создает и инициализирует массив структур *optionsCC
     * и контейнер std::map options
     *
     * 1) Задание названий функций для С реализации
     * 2) Каст std::string -> const char * -> char *
     * 3) Инициализация массива структур
     * 4) Аналогично для С++ только инициализируем контейнер std::map
     * 5) Обработка всех ошибок, что могли быть выброшены в во всех функциях +
     * очистка массива структур
     *
     *
     * @return int - просто-напросто индикатор успешного завершения без
     * выброса исключения и попадания в catch
     */
int main()
{
    menu::Option *optionsCC = nullptr;
    try {
        /*С style*/
        int size = 3;
        optionsCC = new menu::Option [size];
        std::string nameCC1 = "option1", nameCC2 = "help1", nameCC3 = "option3";
        /*кастим std::string -> const char * -> char * */
        char *cname1 = const_cast<char *>(nameCC1.c_str());
        char *cname2 = const_cast<char *>(nameCC2.c_str());
        char *cname3 = const_cast<char *>(nameCC3.c_str());
        optionsCC[0] = (menu::Option){cname1, menu::option1};
        optionsCC[1] = (menu::Option){cname2, menu::option2};
        optionsCC[2] = (menu::Option){cname3, menu::option3};

        /*С++ style*/
        const std::string name1 = "option1", name2 = "help1", name3 = "option3";
        std::map<const std::string, std::function<void()>> options;
        options[name1] = menu::option1;
        options[name2] = menu::option2;
        options[name3] = menu::option3;
//
//  test1
        menu::dialog(optionsCC, size);
        menu::dialog(options);

        delete [] optionsCC; // очистка памяти для C-реализации
    }
    catch (const std::bad_alloc &badAlloc){
        delete [] optionsCC; // очистка памяти для C-реализации
        std::cout << "Not enough memory" << std::endl;
    }
    catch (const std::exception &error) {
        delete [] optionsCC; // очистка памяти для C-реализации
        std::cerr << "Caught exception: " << error.what() << std::endl;
    }
    catch (...) {
        delete [] optionsCC; // очистка памяти для C-реализации
        std::cout << "Unknown Error" << std::endl;
    }
	return 0;
}
