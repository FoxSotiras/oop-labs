#include "../../include/lab1-task1/lib_card.hpp"

LibCard::LibCard() {
    m_book = Book();
    m_return_date = m_receipt_date + std::chrono::months(1);
    m_telephone_number = "";
    m_name = "";
}

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
    m_return_date = m_receipt_date + std::chrono::months(1);
    m_telephone_number = telephone_number;
    m_name = name;
}
