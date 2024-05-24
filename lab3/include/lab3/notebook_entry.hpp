#include <chrono>
#include <string>

#pragma once

class NotebookEntry {
    public:
    NotebookEntry() : m_surname(""), m_name(""), m_telephone_number(""), m_birth_date(),
    m_residential_address("") {}
    NotebookEntry(const std::string& surname, const std::string& name, const std::string& telephone_number,
    const unsigned short& day, const unsigned short& month, const unsigned int& year,
    const std::string& address) : m_surname(surname), m_name(name), m_telephone_number(telephone_number),
    m_birth_date(std::chrono::year(year), std::chrono::month(month),
    std::chrono::day(day)), m_residential_address(address) {}
    NotebookEntry(const NotebookEntry& other) : m_surname(other.m_surname), m_name(other.m_name),
    m_telephone_number(other.m_telephone_number), m_birth_date(other.m_birth_date),
    m_residential_address(other.m_residential_address) {}
    ~NotebookEntry();

    void set_surname(const std::string& surname) { m_surname = surname; }
    std::string get_surname() { return m_surname; }

    void set_name(const std::string& name) { m_name = name; }
    std::string get_name() { return m_name; }

    void set_telephone_number(const std::string& telephone_number) { m_telephone_number = telephone_number; }
    std::string get_telephone_number() { return m_telephone_number; }

    void set_birth_day(const unsigned short& day, const unsigned short& month, const unsigned int& year) {
        m_birth_date = std::chrono::year_month_day(std::chrono::year(year),
        std::chrono::month(month),std::chrono::day(day));
    } 
    std::chrono::year_month_day get_birth_date() { return m_birth_date; }

    void set_address(const std::string& address) { m_residential_address = address; }
    std::string get_address() { return m_residential_address; }

    std::string get_telephone_number(std::vector<NotebookEntry> entrys,
    const std::string& surname, const std::string& name) const;
    bool check_people_living_together(const NotebookEntry& first, const NotebookEntry& second) const;

    protected:
    std::string m_surname;
    std::string m_name;
    std::string m_telephone_number;
    std::chrono::year_month_day m_birth_date;
    std::string m_residential_address;
};
