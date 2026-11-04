#include "Lion.h"
#include <iostream>

Lion::Lion(const std::string& name, int age, int gestationPeriod, bool nursing)
    : Animal(name, "Lion", age, Kind::Lion),
      Mammal(name, "Lion", age, gestationPeriod, nursing, Kind::Lion) {}

Lion::Lion(const Lion& other) : Animal(other), Mammal(other) {}

Lion& Lion::operator=(const Lion& other) {
    if (this != &other) Mammal::operator=(other);
    return *this;
}

void Lion::makeSound() const { std::cout << name_ << ": Roar!" << std::endl; }
void Lion::move() const { std::cout << name_ << " walks and runs." << std::endl; }
std::string Lion::getSpecies() const { return "Lion"; }
void Lion::showBehavior() const { std::cout << name_ << " is a predator; it rests and hunts." << std::endl; }
