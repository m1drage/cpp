#pragma once
#include "Mammal.h"

/**
 * @brief Класс слона.
 * @details Наследуется от Mammal и реализует поведение слона.
 */

class Elephant : public Mammal {
public:
    /** @brief Создаёт слона. */
    Elephant(const std::string& name, int age, int gestationPeriod, bool nursing);
    /** @brief Конструктор копирования. */
    Elephant(const Elephant& other);
    /** @brief Оператор копирующего присваивания. */
    Elephant& operator=(const Elephant& other);
    /** @brief Выводит звук слона. */
    void makeSound() const override;
    /** @brief Выводит способ передвижения слона. */
    void move() const override;
    /** @brief Возвращает название вида. */
    std::string getSpecies() const override;
    /** @brief Выводит описание поведения слона. */
    void showBehavior() const override;
};
