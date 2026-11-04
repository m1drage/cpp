/**
 * @file Parrot.cpp
 * @brief Реализация класса Parrot.
 * @details Содержит реализацию звуков, передвижения
 * и поведения попугая.
 */

#include "Parrot.h"
#include <iostream>

Parrot::Parrot(const std::string& name, int age, double wingspan, bool canFlyValue)
    : Animal(name, "Parrot", age, Kind::Parrot),
      Bird(name, "Parrot", age, wingspan, canFlyValue, Kind::Parrot) {}

Parrot::Parrot(const Parrot& other) : Animal(other), Bird(other) {}

Parrot& Parrot::operator=(const Parrot& other) {
    if (this != &other) Bird::operator=(other);
    return *this;
}

void Parrot::makeSound() const { std::cout << name_ << ": Squawk!" << std::endl; }
void Parrot::move() const { std::cout << name_ << " flies or sits on a perch." << std::endl; }
std::string Parrot::getSpecies() const { return "Parrot"; }
void Parrot::showBehavior() const { std::cout << name_ << " is a bird and can imitate sounds." << std::endl; }
