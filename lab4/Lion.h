#pragma once
#include "Mammal.h"

class Lion : public Mammal {
public:
    Lion(const std::string& name, int age, int gestationPeriod, bool nursing);
    Lion(const Lion& other);
    Lion& operator=(const Lion& other);

    void makeSound() const override;
    void move() const override;
    std::string getSpecies() const override;
    void showBehavior() const override;
};
