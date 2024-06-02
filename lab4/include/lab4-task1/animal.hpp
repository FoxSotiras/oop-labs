#pragma once

#include <string>

class Animal {
public:
    Animal();
    Animal(const std::string& sound);
    Animal(const Animal& other);

    virtual void communicate();
    const std::string& get_sound() const;

    virtual ~Animal();

protected:
    std::string m_sound;
};
