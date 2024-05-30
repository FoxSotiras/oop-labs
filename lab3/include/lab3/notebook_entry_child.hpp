#include "notebook_entry.hpp"

class NotebookEntryChild: public NotebookEntry {
    public:
    NotebookEntryChild():
    NotebookEntry(),
    m_child_surname(""),
    m_child_name(""),
    m_child_birthday(year(), month(), day()) {}

    NotebookEntryChild(
        const NotebookEntry& parent,
        const char* surname,
        const char* name,
        unsigned short p_year,
        unsigned short p_month,
        unsigned short p_day):
    NotebookEntry(parent),
    m_child_surname(surname),
    m_child_name(name),
    m_child_birthday(year(p_year), month(p_month), day(p_day)) {}

    NotebookEntryChild(const NotebookEntryChild& other):
    NotebookEntry(other.m_surname, other.m_name, other.m_telephone, other.m_birthday, other.m_address),
    m_child_surname(other.m_child_surname),
    m_child_name(other.m_child_name),
    m_child_birthday(other.m_child_birthday) {}

    private:
    std::string m_child_surname;
    std::string m_child_name;
    year_month_day m_child_birthday;
};
