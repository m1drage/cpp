#pragma once
#include "Mammal.h"

/**
 * @brief Класс льва.
 * @details Наследуется от Mammal и реализует поведение льва.
 */

class Lion : public Mammal {
public:
/** @brief Создаёт льва. */
    Lion(const std::string& name, int age, int gestationPeriod, bool nursing);
    /** @brief Конструктор копирования. */
    Lion(const Lion& other);
    /** @brief Оператор копирующего присваивания. */
    Lion& operator=(const Lion& other);

    /** @brief Выводит звук льва. */
    void makeSound() const override;
    /** @brief Выводит способ передвижения льва. */
    void move() const override;
    /** @brief Возвращает название вида. */
    std::string getSpecies() const override;
    /** @brief Выводит описание поведения льва. */
    void showBehavior() const override;
};
