#include "animal.hpp"
#include <forward_list>

class Store {
public:
    void add(Animal* object);
    void remove();
    void save();
    void all_communicate();

private:
    std::forward_list<Animal*> m_animals;//Animal*
};
