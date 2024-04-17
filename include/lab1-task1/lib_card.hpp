#include <chrono>
#include "book.hpp"

#pragma once

class LibCard {
    Book m_book;
    std::chrono::year_month_day m_receipt_date
    {std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())};
    std::chrono::year_month_day m_return_date;
    std::string m_telephone_number;
    std::string m_name;

    public:
    LibCard();
    LibCard(const LibCard &other_card);
    LibCard(const Book &book, const std::string &telephone_number,
        const std::string &name);
};
