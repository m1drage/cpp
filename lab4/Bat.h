#pragma once
#include "Mammal.h"
#include "Bird.h"

/**
 * @brief Класс летучей мыши.
 * @details Наследуется одновременно от Mammal и Bird.
 * Использует множественное и виртуальное наследование.
 */

// Летучая мышь одновременно является млекопитающим и летающим существом.
// Animal виртуально наследуется в Mammal и Bird, поэтому подобъект Animal один.
class Bat : public Mammal, public Bird {
public:
    /** @brief Создаёт летучую мышь с характеристиками млекопитающего и птицы. */
    Bat(const std::string& name, int age, int gestationPeriod, bool nursing,
        double wingspan, bool canFly);
    /** @brief Конструктор копирования. */
    Bat(const Bat& other);
    /** @brief Оператор копирующего присваивания. */
    Bat& operator=(const Bat& other);
    /** @brief Выводит звук летучей мыши. */
    void makeSound() const override;
    /** @brief Выводит способ передвижения летучей мыши. */
    void move() const override;
    /** @brief Возвращает название вида. */
    std::string getSpecies() const override;
    /** @brief Выводит описание поведения летучей мыши. */
    void showBehavior() const override;
};
