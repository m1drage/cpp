#include "Book.h"
#include <iostream>
using namespace std;

int Book::count = 0;

// Конструктор без параметров
Book::Book()
{
    title = "No name";
    author = "Unknown";
    year = 2000;
    pages = 100;
    genre.name = "Roman";
    borrowed = false;

    count++;
}

// Конструктор с параметрами
Book::Book(string t, string a, int y, int p, string g)
{
    title = t;
    author = a;
    year = y;
    pages = p;
    genre.name = g;
    borrowed = false;

    if (year < 0)
        year = 0;

    if (pages <= 0)
        pages = 1;

    count++;
}

// Третий конструктор
Book::Book(string t, string a)
{
    title = t;
    author = a;
    year = 2000;
    pages = 100;
    genre.name = "Roman";
    borrowed = false;

    count++;
}

// Явный деструктор
Book::~Book()
{
    
    count--;
    cout << "Destruktor. Ostalos:" << count << endl;
}

// Метод получения данных
string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

int Book::getYear() const
{
    return year;
}

int Book::getPages() const
{
    return pages;
}

bool Book::isBorrowed() const
{
    return borrowed;
}

// Выдать книгу (изменяющий метод)
void Book::borrow()
{
    if (borrowed)
    {
        cout << "The book has already been issued!" << endl;
    }
    else
    {
        borrowed = true;
        cout << "The book has been issued." << endl;
    }
}

// Вернуть книгу (изменяющий метод)
void Book::giveBack()
{
    if (!borrowed)
    {
        cout << "The book is already in the library!" << endl;
    }
    else
    {
        borrowed = false;
        cout << "The book has been returned." << endl;
    }
}

// Добавить страницы (изменяющий метод)
void Book::addPages(int p)
{
    if (p > 0) // Корректность состояния
        pages += p;
    else
        cout << "The number of pages must be greater than 0!" << endl;
}

// Вывод информации
void Book::print() const
{
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << year << endl;
    cout << "Page: " << pages << endl;
    cout << "Genre: " << genre.name << endl;

    if (borrowed)
        cout << "Status: issued" << endl;
    else
        cout << "Status: in the library" << endl;
}

// Количество объектов
int Book::getCount()
{
    return count;
}
