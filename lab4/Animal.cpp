#include "Animal.h"
#include <algorithm>
#include <ostream>
#include <iostream>
#include <stdexcept>

std::size_t Animal::totalCount_ = 0;
std::array<std::size_t, static_cast<std::size_t>(Animal::Kind::Count)> Animal::typeCounts_{};
std::vector<Animal*> Animal::registry_{};

Animal::Animal(const std::string& name, const std::string& species, int age, Kind kind)
    : name_(name), species_(species), age_(age), kind_(kind) {
    if (age < 0) throw std::invalid_argument("Animal age cannot be negative");
    registerSelf();
}

Animal::Animal(const Animal& other)
    : name_(other.name_), species_(other.species_), age_(other.age_), kind_(other.kind_) {
    registerSelf();
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        name_ = other.name_;
        species_ = other.species_;
        age_ = other.age_;
        // Keep kind_ unchanged: an object's concrete type cannot change.
    }
    return *this;
}

Animal::~Animal() { unregisterSelf(); }

void Animal::registerSelf() {
    ++totalCount_;
    ++typeCounts_[static_cast<std::size_t>(kind_)];
    registry_.push_back(this);
}

void Animal::unregisterSelf() noexcept {
    auto it = std::find(registry_.begin(), registry_.end(), this);
    if (it != registry_.end()) registry_.erase(it);
    if (totalCount_ > 0) --totalCount_;
    auto& count = typeCounts_[static_cast<std::size_t>(kind_)];
    if (count > 0) --count;
}

void Animal::showBehavior() const {
    // Default implementation for any animal.
    std::cout << name_ << " - normal animal behavior." << std::endl;
}

const std::string& Animal::getName() const noexcept { return name_; }
int Animal::getAge() const noexcept { return age_; }
Animal::Kind Animal::getKind() const noexcept { return kind_; }

std::size_t Animal::getTotalCount() noexcept { return totalCount_; }

std::size_t Animal::getCountByType(Kind kind) noexcept {
    return typeCounts_[static_cast<std::size_t>(kind)];
}

Animal* Animal::getOldestAnimal() noexcept {
    if (registry_.empty()) return nullptr;
    return *std::max_element(registry_.begin(), registry_.end(),
        [](const Animal* a, const Animal* b) { return a->age_ < b->age_; });
}

std::ostream& operator<<(std::ostream& out, const Animal& animal) {
    out << "Name: " << animal.name_
        << ", species: " << animal.getSpecies()
        << ", age: " << animal.age_;
    return out;
}
