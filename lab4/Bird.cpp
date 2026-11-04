/**
 * @file Bird.cpp
 * @brief Реализация класса Bird.
 * @details Содержит конструкторы и методы работы
 * с характеристиками птиц.
 */
#include "Bird.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

Bird::Bird(const std::string& name, const std::string& species, int age,
           double wingspan, bool canFlyValue, Kind kind)
    : Animal(name, species, age, kind), wingspan_(wingspan), canFly_(canFlyValue) {
    if (!std::isfinite(wingspan) || wingspan < 0)
        throw std::invalid_argument("Wingspan must be a non-negative number");
}

Bird::Bird(const Bird& other)
    : Animal(other), wingspan_(other.wingspan_), canFly_(other.canFly_) {}

Bird& Bird::operator=(const Bird& other) {
    if (this != &other) {
        Animal::operator=(other);
        wingspan_ = other.wingspan_;
        canFly_ = other.canFly_;
    }
    return *this;
}

double Bird::getWingspan() const noexcept { return wingspan_; }
bool Bird::canFly() const noexcept { return canFly_; }

void Bird::showBehavior() const {
    std::cout << name_ << " - bird; "
              << (canFly_ ? "can fly" : "cannot fly") << "." << std::endl;
}
