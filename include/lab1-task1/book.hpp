#include <string>
#include <vector>

#pragma once

class Book {
    unsigned long long m_id;
    std::string m_author;
    std::string m_title;

    public:
    Book(const Book &other_book);
    Book(const unsigned long long &id = 0, const std::string &author = "", const std::string &title = "");

    void set_id(const unsigned long long &id);
    const unsigned long long& get_id() const;
    void set_author(const std::string &author);
    const std::string& get_author() const;
    void set_title(const std::string &title);
    const std::string& get_title() const;

    void print_book() const;
};

class Books {
    std::vector<Book> m_books;

    public:
    Books();

    const Book& operator [](unsigned long long index) {
        return m_books[index];
    }

    const Book& find_book(unsigned long long id) const;
};
