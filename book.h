#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
    int pages;

    Book() = default;
    Book(const string& isbn, const string& title, const string& author, int pages)
        : isbn(isbn), title(title), author(author), pages(pages) {}
};

class BookCollection {
public:
    void addBook(const Book& book);
    void removeBook(const string& isbn);
    Book* searchBook(const string& isbn);
    void listBooks() const;

private:
    unordered_map<string, Book> books;
};

#endif // BOOK_H
