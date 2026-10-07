#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

/** @brief Жанр книги */
struct Genre
{
    string name;
};

/** @brief Класс книги */
class Book
{
private:
    string title;
    string author;
    int year;
    int pages;
    Genre genre;
    bool borrowed;

    /** @brief Количество объектов */
    static int count;

public:
/** @brief Конструктор по умолчанию */
    Book();
    /**
     * @brief Конструктор с параметрами
     * @param t Название
     * @param a Автор
     * @param y Год
     * @param p Количество страниц
     * @param g Жанр
     */
    Book(string t, string a, int y, int p, string g);
    /**
     * @brief Конструктор по названию и автору
     * @param t Название
     * @param a Автор
     */
    Book(string t, string a);

 /** @brief Деструктор */
    ~Book();

    /** @brief Получить название */
    string getTitle() const;
    /** @brief Получить автора */
    string getAuthor() const;
    /** @brief Получить год */
    int getYear() const;
    /** @brief Получить количество страниц */
    int getPages() const;
    /** @brief Проверить, выдана ли книга */
    bool isBorrowed() const;

    /** @brief Выдать книгу */
    void borrow();
    /** @brief Вернуть книгу */
    void giveBack();
    /**
     * @brief Добавить страницы
     * @param p Количество страниц
     */
    void addPages(int p);

    /** @brief Вывести информацию о книге */
    void print() const;

    /** @brief Получить количество объектов */
    static int getCount(); // Статический счетчик
};

#endif