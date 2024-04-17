#include <string>

#pragma once

class Book {
    unsigned long long m_id;
    std::string m_author;
    std::string m_title;

    public:
    Book();
    Book(const Book &other_book);
    Book(const unsigned long long &id, const std::string &author,
        const std::string &title);
};
