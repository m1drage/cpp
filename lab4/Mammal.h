#pragma once
#include "Animal.h"

/**
 * @brief Класс млекопитающих.
 * @details Наследуется от Animal и содержит дополнительные
 * характеристики млекопитающих.
 */

class Mammal : virtual public Animal {
public:
    Mammal(const std::string& name, const std::string& species, int age,
           int gestationPeriod, bool nursing, Kind kind);
    Mammal(const Mammal& other);
    Mammal& operator=(const Mammal& other);
    ~Mammal() override = default;

    int getGestationPeriod() const noexcept;
    bool isNursing() const noexcept;
    void showBehavior() const override;

protected:
    int gestationPeriod_;
    bool nursing_;
};
