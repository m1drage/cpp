#include "Elephant.h"
#include <iostream>

Elephant::Elephant(const std::string& name, int age, int gestationPeriod, bool nursing)
    : Animal(name, "Elephant", age, Kind::Elephant),
      Mammal(name, "Elephant", age, gestationPeriod, nursing, Kind::Elephant) {}

Elephant::Elephant(const Elephant& other) : Animal(other), Mammal(other) {}

Elephant& Elephant::operator=(const Elephant& other) {
    if (this != &other) Mammal::operator=(other);
    return *this;
}

void Elephant::makeSound() const { std::cout << name_ << ": Trumpet sound!" << std::endl; }
void Elephant::move() const { std::cout << name_ << " walks slowly." << std::endl; }
std::string Elephant::getSpecies() const { return "Elephant"; }
void Elephant::showBehavior() const { std::cout << name_ << " is a herbivore and uses its trunk." << std::endl; }
