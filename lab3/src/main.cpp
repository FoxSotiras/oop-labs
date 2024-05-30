#include "../include/lab3/notebook_entry.hpp"

int main() {
    NotebookEntry one;
    NotebookEntry second;
    NotebookEntry third("Buglak", "Dmitriy", "+79951350976", 2005, 9, 29, "Moscow, Dubravnaia");
    std::forward_list<NotebookEntry> list;
    list.push_front(one);
    list.push_front(second);
    list.push_front(third);

    std::cout << "Surname: " << third.get_surname() << '\n';
    std::cout << "Name: " << third.get_name() << '\n';
    std::cout << "Telephone number: " << third.get_telephone() << '\n';
    std::cout << "Birthday: " << third.get_birthday() << '\n';
    std::cout << "Address: " << third.get_address() << '\n';

    std::cout << NotebookEntry::find_telephone(list, "Buglak", "Dmitriy") << '\n';
    std::cout << NotebookEntry::is_living_together(one, third) << '\n';

    return 0;
}
