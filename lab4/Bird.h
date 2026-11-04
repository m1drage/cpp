#pragma once
#include "Animal.h"

/**
 * @brief Класс птиц.
 * @details Наследуется от Animal и хранит информацию
 * о размахе крыльев и способности летать.
 */

class Bird : virtual public Animal {
public:
    /** @brief Создаёт птицу с заданными характеристиками. */
    Bird(const std::string& name, const std::string& species, int age,
         double wingspan, bool canFly, Kind kind);
    /** @brief Конструктор копирования. */
    Bird(const Bird& other);
    /** @brief Оператор копирующего присваивания. */
    Bird& operator=(const Bird& other);
    /** @brief Виртуальный деструктор. */
    ~Bird() override = default;

    /** @brief Возвращает размах крыльев. */
    double getWingspan() const noexcept;
    /** @brief Проверяет способность птицы летать. */
    bool canFly() const noexcept;
    /** @brief Выводит особенности поведения птицы. */
    void showBehavior() const override;

protected:
    double wingspan_;
    bool canFly_;
};
