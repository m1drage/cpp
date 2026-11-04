#pragma once
#include "Bird.h"

class Parrot : public Bird {
public:
    Parrot(const std::string& name, int age, double wingspan, bool canFly);
    Parrot(const Parrot& other);
    Parrot& operator=(const Parrot& other);

    void makeSound() const override;
    void move() const override;
    std::string getSpecies() const override;
    void showBehavior() const override;
};
