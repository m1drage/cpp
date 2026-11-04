#pragma once
#include "Bird.h"

/**
 * @brief Класс попугая.
 * @details Наследуется от Bird и реализует поведение попугая.
 */

class Parrot : public Bird {
public:
    /** @brief Создаёт попугая. */
    Parrot(const std::string& name, int age, double wingspan, bool canFly);
    /** @brief Конструктор копирования. */
    Parrot(const Parrot& other);
    /** @brief Оператор копирующего присваивания. */
    Parrot& operator=(const Parrot& other);
    /** @brief Выводит звук попугая. */
    void makeSound() const override;
    /** @brief Выводит способ передвижения попугая. */
    void move() const override;
    /** @brief Возвращает название вида. */
    std::string getSpecies() const override;
    /** @brief Выводит описание поведения попугая. */
    void showBehavior() const override;
};
