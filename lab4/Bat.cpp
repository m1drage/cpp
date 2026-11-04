/**
 * @file Bat.cpp
 * @brief Реализация класса Bat.
 * @details Содержит реализацию множественного наследования,
 * звуков и передвижения летучей мыши.
 */

#include "Bat.h"
#include <iostream>

Bat::Bat(const std::string& name, int age, int gestationPeriod, bool nursing,
         double wingspan, bool canFlyValue)
    : Animal(name, "Bat", age, Kind::Bat),
      Mammal(name, "Bat", age, gestationPeriod, nursing, Kind::Bat),
      Bird(name, "Bat", age, wingspan, canFlyValue, Kind::Bat) {}

Bat::Bat(const Bat& other)
    : Animal(other), Mammal(other), Bird(other) {}

Bat& Bat::operator=(const Bat& other) {
    if (this != &other) {
        
        Mammal::operator=(other);
        Bird::operator=(other);
    }
    return *this;
}

void Bat::makeSound() const { std::cout << name_ << ": ultrasonic calls!" << std::endl; }
void Bat::move() const { std::cout << name_ << " flies using its membranous wings." << std::endl; }
std::string Bat::getSpecies() const { return "Bat"; }
void Bat::showBehavior() const {
    std::cout << name_ << " is a mammal that can fly; wingspan: "
              << wingspan_ << " m." << std::endl;
}
