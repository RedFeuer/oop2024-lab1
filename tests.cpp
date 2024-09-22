#include <gtest/gtest.h>
#include "../dialog.h"
#include "../internal.h"

// Тесты для dialog.cpp
TEST(DialogTestCXX, EnterEOF) {
    std::string name1 = "option1", name2 = "help1", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::istringstream input("");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_THROW(menu::dialog(options), std::runtime_error);
}

TEST(DialogTestC, EnterEOF) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "help1", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_THROW(menu::dialog(optionsCC, size), std::runtime_error);
    delete [] optionsCC;
}

TEST(DialogTestCXX, EnterHelp) {
    /*РАБОТАЕТ НЕВЕРНО
     * почему-то вместо help попадает EOF
     * ИСПРАВИЛ, ЛЮБОЙ НЕ EOF ВВОД ДОЛЖЕН
     * КОНЧАТЬСЯ ЧЕРЕЗ exit*/
    std::string name1 = "option1", name2 = "help1", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::string word = "help";
    std::istringstream input("help\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(options));
}

TEST(DialogTestC, EnterHelp) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "help1", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("help\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(optionsCC, size));
    delete [] optionsCC;
}

TEST(DialogTestCXX, ExitCheckTest) {
    std::string name1 = "option1", name2 = "exit", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::string word = "help";
    std::istringstream input("help\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_THROW(menu::dialog(options), std::runtime_error);
}

TEST(DialogTestC, ExitCheckTest) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "exit", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("help\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_THROW(menu::dialog(optionsCC, size), std::runtime_error);
    delete [] optionsCC;
}

TEST(DialogTestCXX, HelpCheckTest) {
    std::string name1 = "option1", name2 = "help", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::string word = "help";
    std::istringstream input("help\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_THROW(menu::dialog(options), std::runtime_error);
}

TEST(DialogTestC, HelpCheckTest) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "help", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("help\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_THROW(menu::dialog(optionsCC, size), std::runtime_error);
    delete [] optionsCC;
}

TEST(DialogTestCXX, EnterOption1) {
    std::string name1 = "option1", name2 = "option2", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::string word = "help";
    std::istringstream input("option1\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(options));
}

TEST(DialogTestC, EnterOption1) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "option2", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("option1\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(optionsCC, size));
    delete [] optionsCC;
}

TEST(DialogTestCXX, EnterOption2) {
    std::string name1 = "option1", name2 = "option2", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::string word = "help";
    std::istringstream input("option2\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(options));
}

TEST(DialogTestC, EnterOption2) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "option2", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("option2\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(optionsCC, size));
    delete [] optionsCC;
}

TEST(DialogTestCXX, EnterOption3) {
    std::string name1 = "option1", name2 = "option2", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::string word = "help";
    std::istringstream input("option3\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(options));
}

TEST(DialogTestC, EnterOption3) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "option2", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("option3\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(optionsCC, size));
    delete [] optionsCC;
}

TEST(DialogTestCXX, NoMatches) {
    std::string name1 = "option1", name2 = "option2", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::string word = "help";
    std::istringstream input("option123\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(options));
}

TEST(DialogTestC, NoMatches) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "option2", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("option123\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(optionsCC, size));
    delete [] optionsCC;
}

TEST(DialogTestCXX, AmbiguousName) {
    std::string name1 = "option1", name2 = "option2", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::string word = "help";
    std::istringstream input("option\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(options));
}

TEST(DialogTestC, CinFail) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "option2", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("option\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(optionsCC, size));
    delete [] optionsCC;
}

TEST(DialogTestCXX, CinFail) {
    std::string name1 = "option1", name2 = "option2", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::string word = "help";
    std::istringstream input("option\nexit\n");
    std::cin.rdbuf(input.rdbuf());

    std::cin.clear();
    std::cin.setstate(std::ios::failbit);
    EXPECT_THROW(menu::dialog(options), std::runtime_error);
}

TEST(DialogTestC, AmbiguousName) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "option2", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("option\nexit\n");
    std::cin.rdbuf(input.rdbuf());

    std::cin.clear();
    std::cin.setstate(std::ios::failbit);
    EXPECT_THROW(menu::dialog(optionsCC, size), std::runtime_error);
    delete [] optionsCC;
}

TEST(DialogTestCXX, EmptyCin) {
    std::string name1 = "option1", name2 = "option2", name3 = "option3";
    std::map<const std::string, std::function<void()>> options;
    options[name1] = menu::option1;
    options[name2] = menu::option2;
    options[name3] = menu::option3;
    std::string word = "help";
    std::istringstream input("\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(options));
}

TEST(DialogTestC, EmptyCin) {
    int size = 3;
    auto *optionsCC = new menu::Option [size];
    std::string nameCC1 = "option1", nameCC2 = "option2", nameCC3 = "option3";
    /*кастим std::string -> const char * -> char * */
    char *cname1 = const_cast<char *>(nameCC1.c_str());
    char *cname2 = const_cast<char *>(nameCC2.c_str());
    char *cname3 = const_cast<char *>(nameCC3.c_str());
    optionsCC[0] = (menu::Option){cname1, menu::option1};
    optionsCC[1] = (menu::Option){cname2, menu::option2};
    optionsCC[2] = (menu::Option){cname3, menu::option3};
    std::istringstream input("\nexit\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(menu::dialog(optionsCC, size));
    delete [] optionsCC;
}

