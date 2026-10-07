#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
    // Создаю три книги разными конструкторами (3 объекта)
    Book book1;

    Book book2(
        "War and peace",
        "Lev Tolstoi",
        1869,
        1225,
        "Roman"
    );

    Book book3("Harry Potter", "J.K. Rowling");

    cout << "=== BOOKS ===" << endl;

    cout << "\nBook 1:" << endl;
    book1.print();

    cout << "\nBook 2:" << endl;
    book2.print();

    cout << "\nBook 3:" << endl;
    book3.print();

    cout << "\n=== CORRECT OPERATIONS ===" << endl;

    book1.borrow();
    book1.addPages(20);

    book1.print();

    cout << "\n=== INCORRECT OPERATIONS ===" << endl;

    // Пытаюсь выдать уже выданную книгу
    book1.borrow();

    // Пытаюсь добавить отрицательное количество страниц
    book1.addPages(-50);

    cout << "\nThe condition of the book:" << endl;
    book1.print();

    cout << "\n=== INDEPENDENCE CHECK ===" << endl;

    book2.borrow();

    cout << "\nBook 2:" << endl;
    book2.print();

    cout << "\nBook 3:" << endl;
    book3.print();

    cout << "\nNumber of objects: "
         << Book::getCount() << endl;

    return 0;
}




