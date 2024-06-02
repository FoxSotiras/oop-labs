#pragma once

#include <chrono>
#include <forward_list>
#include <string>

using namespace std::chrono;

class NotebookEntry {
    public:
    NotebookEntry();
    NotebookEntry(
        const std::string& surname,
        const std::string& name,
        const std::string& telephone,
        unsigned short p_year,
        unsigned short p_month,
        unsigned short p_day,
        const std::string& address
    );
    NotebookEntry(
        const std::string& surname,
        const std::string& name,
        const std::string& telephone,
        year_month_day p_day,
        const std::string& address
    );
    NotebookEntry(const NotebookEntry& other);

    virtual ~NotebookEntry();

    void set_surname(const std::string& surname);
    const std::string& get_surname() const;

    void set_name(const std::string& name);
    const std::string& get_name() const;

    void set_telephone(const std::string& telephone);
    const std::string& get_telephone() const;

    void set_birthday(
        unsigned short p_year,
        unsigned short p_month,
        unsigned short p_day
    );
    void set_birthday(const year_month_day& p_day);
    const year_month_day& get_birthday() const;

    void set_address(const std::string& address);
    const std::string& get_address() const;

    static const std::string& find_telephone(const std::forward_list<NotebookEntry>& entrys, const char* surname, const char* name);
    static bool is_living_together(const NotebookEntry& first, const NotebookEntry& second);

    protected:
    std::string m_surname;
    std::string m_name;
    std::string m_telephone;
    year_month_day m_birthday;
    std::string m_address;
};
