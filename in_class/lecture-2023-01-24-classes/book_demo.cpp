
#include <iostream>
#include "Book.h"
using std::cout;
using std::endl;

int main() {
    Book book1("Title", "Author", 1234);
    Book* book2 = new Book("WTF", "O'Reilly", 2017);

    cout << book1.str() << endl;
    cout << book2->str() << endl;

    delete book2;
}