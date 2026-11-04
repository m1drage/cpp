/**
 * @file Mammal.cpp
 * @brief Реализация класса Mammal.
 * @details Содержит конструкторы и методы работы
 * с характеристиками млекопитающих.
 */
#include "Mammal.h"
#include <iostream>
#include <stdexcept>

Mammal::Mammal(const std::string& name, const std::string& species, int age,
               int gestationPeriod, bool nursing, Kind kind)
    : Animal(name, species, age, kind),
      gestationPeriod_(gestationPeriod), nursing_(nursing) {
    if (gestationPeriod < 0) throw std::invalid_argument("Gestation period cannot be negative");
}

Mammal::Mammal(const Mammal& other)
    : Animal(other), gestationPeriod_(other.gestationPeriod_), nursing_(other.nursing_) {}

Mammal& Mammal::operator=(const Mammal& other) {
    if (this != &other) {
        Animal::operator=(other);
        gestationPeriod_ = other.gestationPeriod_;
        nursing_ = other.nursing_;
    }
    return *this;
}

int Mammal::getGestationPeriod() const noexcept { return gestationPeriod_; }
bool Mammal::isNursing() const noexcept { return nursing_; }

void Mammal::showBehavior() const {
    std::cout << name_ << " - mammal; nursing: "
              << (nursing_ ? "yes" : "no") << "." << std::endl;
}
