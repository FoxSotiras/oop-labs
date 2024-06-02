#include "../include/lab3/notebook_entry_child.hpp"
#include <stdexcept>

NotebookEntryChild::NotebookEntryChild():
    NotebookEntry(),
    m_child_surname(""),
    m_child_name(""),
    m_child_birthday(year(), month(), day()) {}

NotebookEntryChild::NotebookEntryChild(
    const NotebookEntry& parent,
    const std::string& surname,
    const std::string& name,
    unsigned short p_year,
    unsigned short p_month,
    unsigned short p_day
):
    NotebookEntry(parent),
    m_child_surname(surname),
    m_child_name(name),
    m_child_birthday(year(p_year), month(p_month), day(p_day)) {
    if (m_surname.empty() || m_name.empty() || p_year < 1900 || !m_child_birthday.ok()) {
        throw std::runtime_error("Error while creating the object.");
    }
}

NotebookEntryChild::NotebookEntryChild(const NotebookEntryChild& other):
    NotebookEntry(other.m_surname, other.m_name, other.m_telephone, other.m_birthday, other.m_address),
    m_child_surname(other.m_child_surname),
    m_child_name(other.m_child_name),
    m_child_birthday(other.m_child_birthday) {}

void NotebookEntryChild::set_child_surname(const std::string& surname) { m_surname = surname; }
const std::string& NotebookEntryChild::get_child_surname() const { return m_surname; }

void NotebookEntryChild::set_child_name(const std::string& name) { m_name = name; }
const std::string& NotebookEntryChild::get_child_name() const { return m_name; }

void NotebookEntryChild::set_child_birthday(
    unsigned short p_year,
    unsigned short p_month,
    unsigned short p_day) { 
    m_birthday = year_month_day(year(p_year), month(p_month), day(p_day)); 
}
void NotebookEntryChild::set_child_birthday(const year_month_day& p_day) { m_birthday = p_day; }
const year_month_day& NotebookEntryChild::get_child_birthday() const { return m_birthday; }
