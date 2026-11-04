#pragma once
#include "Mammal.h"
#include "Bird.h"

// Летучая мышь одновременно является млекопитающим и летающим существом.
// Animal виртуально наследуется в Mammal и Bird, поэтому подобъект Animal один.
class Bat : public Mammal, public Bird {
public:
    Bat(const std::string& name, int age, int gestationPeriod, bool nursing,
        double wingspan, bool canFly);
    Bat(const Bat& other);
    Bat& operator=(const Bat& other);

    void makeSound() const override;
    void move() const override;
    std::string getSpecies() const override;
    void showBehavior() const override;
};
