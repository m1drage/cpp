#pragma once
#include "Animal.h"

/**
 * @brief Класс млекопитающих.
 * @details Наследуется от Animal и содержит дополнительные
 * характеристики млекопитающих.
 */

class Mammal : virtual public Animal {
public:
    /** @brief Создаёт млекопитающее. */
    Mammal(const std::string& name, const std::string& species, int age,
           int gestationPeriod, bool nursing, Kind kind);
    /** @brief Конструктор копирования. */
    Mammal(const Mammal& other);
    /** @brief Оператор копирующего присваивания. */
    Mammal& operator=(const Mammal& other);
    /** @brief Деструктор млекопитающего. */
    ~Mammal() override = default;
    /** @brief Возвращает срок беременности. */
    int getGestationPeriod() const noexcept;
    /** @brief Проверяет, кормит ли животное детёнышей. */
    bool isNursing() const noexcept;
    /** @brief Выводит особенности поведения млекопитающего. */
    void showBehavior() const override;

protected:
    int gestationPeriod_;
    bool nursing_;
};
