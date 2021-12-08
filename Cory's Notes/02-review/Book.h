

#include <iostream>
#include <string>

using std::string;


class Book {

 public:

  string title;
  string author;

  Book(string t, string a) : title(t), author(a) {}

  string getTitle() const { return title; }

  string getAuthor() const { return author; }

  void setTitle(string title);

  void setAuthor(string author);

  string toString() const;

};


