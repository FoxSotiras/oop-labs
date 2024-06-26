#include "../../include/lab1-task1/book.hpp"
#include <iostream>
#include <stdexcept>

Book::Book(const Book &other_book) {
    m_id = other_book.m_id;
    m_author = other_book.m_author;
    m_title = other_book.m_title;
}

Book::Book(const unsigned long long &id, const std::string &author, const std::string &title) {
    m_id = id;
    m_author = author;
    m_title = title;
}

const unsigned long long& Book::get_id() const {
    return m_id;
}

const std::string& Book::get_author() const {
    return m_author;
}

const std::string& Book::get_title() const {
    return m_title;
}

void Book::print_book() const {
    std::cout << "Book id: " << m_id << '\n';
    std::cout << "Book author: " << m_author << '\n';
    std::cout << "Book title: " << m_title << '\n';
}

Books::Books() {
    std::vector<std::string> authors = {"Dostoevsky", "Tolstoy", "Bulgakov", "Bradbery", "Pushkin"};
    std::vector<std::string> titles = {"Crime and Punishment", "War and Piece", "Master and Margarita", "451 Farenheit", "Capitan's daughter"};

    for (unsigned short i = 0; i < 5; ++i)
    {
        Book book(i + 1, authors[i], titles[i]);
        m_books.push_back(book);
    }
}

void Books::print_books() {
    std::cout << "Book list:" << '\n';
    for (size_t i = 0; i < m_books.size(); ++i) {
        std::cout << i + 1 << ". " << "ID: " << m_books[i].get_id() << "\n   " << "Author: " << m_books[i].get_author()
        << "\n   " << "Title: " << m_books[i].get_title() << '\n';
    }
}

const Book& Books::find_book(unsigned long long id) const {
    for (const Book &book : m_books) {
        if(book.get_id() == id) {
            return book;
        }
    }

    throw std::invalid_argument("There is no book with that id.");
}
