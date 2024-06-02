#include "../include/lab3/notebook_entry.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

namespace {
    bool check_valid(
        const std::string& surname,
        const std::string& name,
        const std::string& telephone,
        year_month_day p_day,
        const std::string& address
    ) {
        return surname.empty() || name.empty() || telephone.empty() || !p_day.ok() || address.empty();
    }
}

NotebookEntry::NotebookEntry():
    m_surname(""),
    m_name(""),
    m_telephone(""),
    m_birthday(year(), month(), day()),
    m_address("") {}

NotebookEntry::NotebookEntry(
    const std::string& surname,
    const std::string& name,
    const std::string& telephone,
    unsigned short p_year,
    unsigned short p_month,
    unsigned short p_day,
    const std::string& address
):
    m_surname(surname),
    m_name(name),
    m_telephone(telephone),
    m_birthday(year(p_year), month(p_month), day(p_day)),
    m_address(address) {
    if (check_valid(m_surname, m_name, m_telephone, m_birthday, m_address)) {
        throw std::runtime_error("Error while creating the object.");
    }
}

NotebookEntry::NotebookEntry(
        const std::string& surname,
        const std::string& name,
        const std::string& telephone,
        year_month_day p_day,
        const std::string& address
):
    m_surname(surname),
    m_name(name),
    m_telephone(telephone),
    m_birthday(p_day),
    m_address(address) {
    if (check_valid(m_surname, m_name, m_telephone, m_birthday, m_address)) {
        throw std::runtime_error("Error while creating the object.");
    }
}

NotebookEntry::NotebookEntry(const NotebookEntry& other):
    m_surname(other.m_surname),
    m_name(other.m_name),
    m_telephone(other.m_telephone),
    m_birthday(other.m_birthday),
    m_address(other.m_address) {}

NotebookEntry::~NotebookEntry() {
    std::cout << "The object has been deleted" << '\n';
}

void NotebookEntry::set_surname(const std::string& surname) { m_surname = surname; }
const std::string& NotebookEntry::get_surname() const { return m_surname; }

void NotebookEntry::set_name(const std::string& name) { m_name = name; }
const std::string& NotebookEntry::get_name() const { return m_name; }

void NotebookEntry::set_telephone(const std::string& telephone) { m_telephone = telephone; }
const std::string& NotebookEntry::get_telephone() const { return m_telephone; }

void NotebookEntry::set_birthday(
    unsigned short p_year,
    unsigned short p_month,
    unsigned short p_day) { 
    m_birthday = year_month_day(year(p_year), month(p_month), day(p_day)); 
}
void NotebookEntry::set_birthday(const year_month_day& p_day) { m_birthday = p_day; }
const year_month_day& NotebookEntry::get_birthday() const { return m_birthday; }

void NotebookEntry::set_address(const std::string& address) { m_address = address; }
const std::string& NotebookEntry::get_address() const { return m_address; }

const std::string& NotebookEntry::find_telephone(const std::forward_list<NotebookEntry>& entrys, const char* surname, const char* name) {
    auto begin = entrys.begin();
    auto end = entrys.end();
    while (begin != end) {
        if (begin->m_surname == surname && begin->m_name == name) {
            return begin->m_telephone;
        }
        ++begin;
    }

    throw std::runtime_error("Object with that parameters is not found");
}

bool NotebookEntry::is_living_together(const NotebookEntry& first, const NotebookEntry& second) {
    return first.m_address == second.m_address;
}
