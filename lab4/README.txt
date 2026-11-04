Лабораторная работа №3 — Вариант 10 «Животные в зоопарке»
Стандарт: C++17. Сборка выполняется вручную, без Make/CMake.

Состав:
Animal, Mammal, Bird, Lion, Elephant, Parrot, Bat — отдельные .h/.cpp;
ZooLoader — чтение объектов из animals.txt;
main.cpp — единый клиентский тест;
animals.txt — начальные данные.

Иерархия:
Animal (абстрактный)
  Mammal : virtual Animal
    Lion
    Elephant
  Bird : virtual Animal
    Parrot
  Bat : Mammal, Bird

Виртуальное наследование Animal в Mammal и Bird гарантирует, что Bat содержит
только один подобъект Animal. Animal::makeSound, move и getSpecies — чисто
виртуальные. showBehavior имеет реализацию по умолчанию и переопределяется
в промежуточных и конкретных классах.

Строки хранятся в std::string, поэтому копирование является глубоким по
семантике владения и не требует ручного управления памятью. Виртуальный
деструктор обеспечивает корректное удаление через Animal*.

Счётчики отражают число живых объектов. Копирование увеличивает счётчик,
уничтожение уменьшает, присваивание не меняет число объектов.
getOldestAnimal возвращает указатель на самый старый живой объект.
Указатель действителен, пока соответствующий объект существует.

Дружественная функция: operator<<(std::ostream&, const Animal&).

ВАЖНО: в условии есть противоречие: ровно 10 записей и минимум по 3 объекта
каждого из четырёх конкретных классов одновременно невозможны. Файл содержит
10 записей: 3 Lion, 3 Elephant, 3 Parrot, 1 Bat. Для выполнения минимума 3
объекта каждого конкретного класса добавьте ещё две строки Bat.

Сборка в Linux (выполнять из каталога проекта):

1) Общие объектные файлы для статической библиотеки:
g++ -std=c++17 -Wall -Wextra -pedantic -O2 -c Animal.cpp Mammal.cpp Bird.cpp Lion.cpp Elephant.cpp Parrot.cpp Bat.cpp ZooLoader.cpp

2) Статическая библиотека:
ar rcs liblab3.a Animal.o Mammal.o Bird.o Lion.o Elephant.o Parrot.o Bat.o ZooLoader.o

3) Тестовая программа со статической библиотекой:
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -L. -llab3 -o test_static

4) Объектные файлы для динамической библиотеки (обязательно -fPIC):
g++ -std=c++17 -Wall -Wextra -pedantic -O2 -fPIC -c Animal.cpp Mammal.cpp Bird.cpp Lion.cpp Elephant.cpp Parrot.cpp Bat.cpp ZooLoader.cpp

5) Динамическая библиотека:
g++ -shared -o liblab3.so Animal.o Mammal.o Bird.o Lion.o Elephant.o Parrot.o Bat.o ZooLoader.o

6) Тестовая программа с динамической библиотекой:
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -L. -llab3 -Wl,-rpath,'$ORIGIN' -o test_shared

7) Запуск:
./test_static animals.txt
./test_shared animals.txt

Для Windows (MinGW-w64) используйте те же исходники:
Статическая:
g++ -std=c++17 -c Animal.cpp Mammal.cpp Bird.cpp Lion.cpp Elephant.cpp Parrot.cpp Bat.cpp ZooLoader.cpp
ar rcs lab3.lib Animal.o Mammal.o Bird.o Lion.o Elephant.o Parrot.o Bat.o ZooLoader.o
g++ -std=c++17 main.cpp lab3.lib -o test_static.exe

Динамическая:
g++ -std=c++17 -shared -o lab3.dll Animal.cpp Mammal.cpp Bird.cpp Lion.cpp Elephant.cpp Parrot.cpp Bat.cpp ZooLoader.cpp
g++ -std=c++17 main.cpp -L. -llab3 -o test_shared.exe
Для запуска test_shared.exe положите lab3.dll рядом с exe либо добавьте
каталог библиотеки в PATH. При использовании MinGW импортная библиотека
обычно создаётся компоновщиком как liblab3.dll.a; имя lab3.lib характерно
для MSVC/совместимых инструментов.

Примечание: для полностью одинакового клиентского кода обе программы
компилируются из одного main.cpp; различается только библиотека при линковке.
