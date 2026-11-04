#pragma once
#include "Animal.h"

class Bird : virtual public Animal {
public:
    Bird(const std::string& name, const std::string& species, int age,
         double wingspan, bool canFly, Kind kind);
    Bird(const Bird& other);
    Bird& operator=(const Bird& other);
    ~Bird() override = default;

    double getWingspan() const noexcept;
    bool canFly() const noexcept;
    void showBehavior() const override;

protected:
    double wingspan_;
    bool canFly_;
};
