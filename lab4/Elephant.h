#pragma once
#include "Mammal.h"

class Elephant : public Mammal {
public:
    Elephant(const std::string& name, int age, int gestationPeriod, bool nursing);
    Elephant(const Elephant& other);
    Elephant& operator=(const Elephant& other);

    void makeSound() const override;
    void move() const override;
    std::string getSpecies() const override;
    void showBehavior() const override;
};
