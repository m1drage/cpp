#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

struct Genre
{
    string name;
};

class Book
{
private:
    string title;
    string author;
    int year;
    int pages;
    Genre genre;
    bool borrowed;

    static int count;

public:
    Book();
    Book(string t, string a, int y, int p, string g);
    Book(string t, string a);

    ~Book();

    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
    int getPages() const;
    bool isBorrowed() const;

    void borrow();
    void giveBack();
    void addPages(int p);

    void print() const;

    static int getCount(); // Статический счетчик
};

#endif