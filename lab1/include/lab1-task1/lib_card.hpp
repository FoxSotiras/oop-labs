#include "book.hpp"
#include <chrono>

#pragma once

class LibCard {
    Book m_book;
    std::chrono::year_month_day m_receipt_date{std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())};
    std::chrono::year_month_day m_return_date;
    std::string m_telephone_number;
    std::string m_name;

    public:
    LibCard(const LibCard &other_card);
    LibCard(const Book &book = Book(), const std::string &telephone_number = "", const std::string &name = "");

    const std::chrono::year_month_day& get_return_date() const;

    void fill_card();
    void print_card() const;
};

class LibCards {
    std::vector<LibCard> m_cards;

    public:
    const LibCard& operator [](unsigned long long index) {
        return m_cards[index];
    }

    void create_card();
    void sort_cards();
    std::vector<LibCard> get_list();
};
