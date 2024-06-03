#include "animal.hpp"
#include <forward_list>

class Store {
public:
    void add(const Animal& object);
    void remove();
    void save();

private:
    std::forward_list<Animal> m_animals;//Animal*
};
