#include "../../include/lab1-task1/book.hpp"

Book::Book() {
    m_id = 0;
    m_author = "";
    m_title = "";
}

Book::Book(const Book &other_book) {
    m_id = other_book.m_id;
    m_author = other_book.m_author;
    m_title = other_book.m_title;
}

Book::Book(const unsigned long long &id, const std::string &author,
        const std::string &title) {
    m_id = id;
    m_author = author;
    m_title = title;
}
