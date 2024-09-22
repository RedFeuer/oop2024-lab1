# Menu

Menu — это библиотека для организации пользовательского меню с поддержкой callback-функций, частичного ввода и специальных команд.

## Описание

Данный проект предоставляет функции для создания и управления пользовательским меню. Меню может принимать список опций, каждая из которых связана с callback-функцией, и предоставлять пользователю возможность выбора нужной опции с клавиатуры.

Особенности:
- Поддержка частичного ввода для опций (например, для опции «exit» можно ввести «e» или «ex»).
- Специальные опции «help» (вывод списка всех доступных опций) и «exit» (выход из меню).
- Обработка пользовательского ввода с возможностью завершения при достижении EOF.
- Возможность использования как C-стилей массивов структур, так и C++ контейнеров (std::map, std::vector).

Проект включает две версии функций для создания меню:
1. С использованием C-стилей массивов и структур.
2. С использованием контейнеров из стандартной библиотеки C++.

## Установка

1. Клонируйте репозиторий:
   ```bash
   git clone https://github.com/RedFeuer/oop2024-lab1.git
   ```
2. Перейдите в директорию проекта:  
3. Соберите проект с помощью CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
4. Запустите проект:
   ```bash
   ./menu
   ```
5. Использование:  
   help: вывод списка всех доступных опций:  
   exit: выход из меню:
   

6. Тестирование:  
   Для получение покрытия проекта тестами посредством GoogleTest:
   ```bash
   cd tests
   cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
   cmake --build build
   cd build && ./menu_test && cd ..
   lcov --directory . --capture --output-file coverage.info --rc geninfo_unexecuted_blocks=1 --ignore-errors mismatch
   genhtml coverage.info --output-directory out
   ```
7. Вклад в проект:  
   1. Форкните репозиторий.
   2. Создайте новую ветку:
   ```bash
   git checkout -b feature/my-feature
   ```
   3. Внесите изменения и закоммитьте их
   ```bash
   git commit -am 'ADDED: new feature'
   ```
   4. Сделайте push изменений в ветку
   ```bash
   git push origin feature/my-feature
   ```
   5. Создайте pull request.  

## Лицензия
Этот проект лицензирован под MIT License - смотрите файл [LICENSE](LICENSE), чтобы узнать подробнее.


