#pragma once

#include <chrono>
#include <forward_list>
#include <iostream>
#include <string>

using namespace std::chrono;

class NotebookEntry {
    public:
    NotebookEntry():
    m_surname(""),
    m_name(""),
    m_telephone(""),
    m_birthday(year(), month(), day()),
    m_address("") {}

    NotebookEntry(
        const char* surname,
        const char* name,
        const char* telephone,
        unsigned short p_year,
        unsigned short p_month,
        unsigned short p_day,
        const char* address):
    m_surname(surname),
    m_name(name),
    m_telephone(telephone),
    m_birthday(year(p_year), month(p_month), day(p_day)),
    m_address(address) {}

    NotebookEntry(
        const std::string& surname,
        const std::string& name,
        const std::string& telephone,
        year_month_day p_day,
        const std::string& address):
    m_surname(surname),
    m_name(name),
    m_telephone(telephone),
    m_birthday(p_day),
    m_address(address) {}

    NotebookEntry(const NotebookEntry& other):
    m_surname(other.m_surname),
    m_name(other.m_name),
    m_telephone(other.m_telephone),
    m_birthday(other.m_birthday),
    m_address(other.m_address) {}

    virtual ~NotebookEntry() { std::cout << "The object has been deleted" << '\n'; }

    void set_surname(const char* surname) { m_surname = surname; }
    const std::string& get_surname() const { return m_surname; }

    void set_name(const char* name) { m_name = name; }
    const std::string& get_name() const { return m_name; }

    void set_telephone(const char* telephone) { m_telephone = telephone; }
    const std::string& get_telephone() const { return m_telephone; }

    void set_birthday(
        unsigned short p_year,
        unsigned short p_month,
        unsigned short p_day) { 
        m_birthday = year_month_day(year(p_year), month(p_month), day(p_day)); 
    }
    const year_month_day& get_birthday() const { return m_birthday; }

    void set_address(const char* address) { m_address = address; }
    const std::string& get_address() const { return m_address; }

    static const std::string& find_telephone(const std::forward_list<NotebookEntry>& entrys, const char* surname, const char* name);
    static bool is_living_together(const NotebookEntry& first, const NotebookEntry& second);

    protected:
    std::string m_surname;
    std::string m_name;
    std::string m_telephone;
    year_month_day m_birthday;
    std::string m_address;
};
