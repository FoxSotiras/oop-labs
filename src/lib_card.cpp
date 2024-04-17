#include "../include/lab1-task1/lib_card.hpp"
#include <iostream>
#include <stdexcept>

Books books;

LibCard::LibCard(const LibCard &other_card) {
    m_book = other_card.m_book;
    m_receipt_date = other_card.m_receipt_date;
    m_return_date = other_card.m_return_date;
    m_telephone_number = other_card.m_telephone_number;
    m_name = other_card.m_name;
}

LibCard::LibCard(const Book &book, const std::string &telephone_number,
    const std::string &name) {
    m_book = book;
    m_return_date = std::chrono::sys_days(m_receipt_date)
    + std::chrono::days(30);
    m_telephone_number = telephone_number;
    m_name = name;
}

void LibCard::fill_card() {
    unsigned long long id = 0;

    std::cout << "Enter information about library card:" << '\n';

    book_id:
    std::cout << "Enter the book id: ";
    std::cin >> id;
    try {
        m_book = books.find_book(id);
    } catch (const std::exception &error) {
        std::cout << error.what() << '\n';
        goto book_id;
    }

    std::cout << "Enter a contact telephone: ";
    std::getline(std::cin >> std::ws, m_telephone_number);
    std::cout << "Enter a contact name: ";
    std::getline(std::cin >> std::ws, m_name);
}

void LibCard::print_card() {
    std::cout << "Information about library card:" << '\n';
    std::cout << "The information about a book: " << '\n';
    m_book.print_book();
    std::cout << "Receipt date: " << static_cast<unsigned int>(m_receipt_date.day()) << '.'
    << static_cast<unsigned int>(m_receipt_date.month()) << '.'
    << static_cast<int>(m_receipt_date.year()) << '\n';
    std::cout << "Return date: " << static_cast<unsigned int>(m_return_date.day()) << '.'
    << static_cast<unsigned int>(m_return_date.month()) << '.'
    << static_cast<int>(m_return_date.year()) << '\n';
    std::cout << "Contact telephone: " << m_telephone_number << '\n';
    std::cout << "Contact name: " << m_name << '\n';
}
