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

LibCard::LibCard(const Book &book, const std::string &telephone_number, const std::string &name) {
    m_book = book;
    m_return_date = std::chrono::sys_days(m_receipt_date)
    + std::chrono::days(30);
    m_telephone_number = telephone_number;
    m_name = name;
}

const std::chrono::year_month_day& LibCard::get_return_date() const {
    return m_return_date;
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

void LibCard::print_card() const {
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

void LibCards::create_card() {
    LibCard card;
    card.fill_card();
    m_cards.push_back(card);
}

void LibCards::sort_cards() {
    unsigned long long min_index = 0;
    LibCard elem;

    for (unsigned long long i = 0; i < m_cards.size() - 1; ++i) {
        min_index = i;
        for (unsigned long long j = i + 1; j < m_cards.size(); ++j)
        {
            elem = m_cards[j];
            if (elem.get_return_date() < m_cards[min_index].get_return_date()) {
                min_index = j;
            }
        }
        if (min_index != i) {
            m_cards.insert(m_cards.begin() + i, m_cards[min_index]);
            m_cards.erase(m_cards.begin() + min_index + 1);
        }
    }
}

std::vector<LibCard> LibCards::get_list() {
    std::vector<LibCard> list;

    for (LibCard &card : m_cards) {
        if ((std::chrono::sys_days(card.get_return_date()) - std::chrono::weeks(1)) <=
            std::chrono::sys_days(std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()))) {
            list.push_back(card);
        }
    }

    return list;
}
