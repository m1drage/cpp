#pragma once
#include <array>
#include <cstddef>
#include <iosfwd>
#include <string>
#include <vector>

/**
 * @brief Абстрактный базовый класс животного.
 * @details Содержит общие данные и методы для всех животных.
 * Ведёт подсчёт общего количества животных и количества по типам.
 */
class Animal {
public:
    /** @brief Перечисление типов животных. */
    enum class Kind { Lion = 0, Elephant = 1, Parrot = 2, Bat = 3, Count = 4 };

    /** @brief Создаёт животное с заданными параметрами. */
    Animal(const std::string& name, const std::string& species, int age, Kind kind);
    /** @brief Конструктор копирования. */
    Animal(const Animal& other);
    /** @brief Оператор копирующего присваивания. */
    Animal& operator=(const Animal& other);
    /** @brief Виртуальный деструктор. */
    virtual ~Animal();

    /** @brief Издаёт звук животного. */
    virtual void makeSound() const = 0;
    /** @brief Описывает передвижение животного. */
    virtual void move() const = 0;
    /** @brief Возвращает название вида. */
    virtual std::string getSpecies() const = 0;

    // Виртуальная функция с реализацией по умолчанию.
    /** @brief Выводит описание поведения животного. */
    virtual void showBehavior() const;

    const std::string& getName() const noexcept;
    int getAge() const noexcept;
    Kind getKind() const noexcept;

    static std::size_t getTotalCount() noexcept;
    static std::size_t getCountByType(Kind kind) noexcept;
    /** @brief Находит самое старое живое животное. */
    static Animal* getOldestAnimal() noexcept;

    /** @brief Перегружает оператор вывода информации о животном. */
    friend std::ostream& operator<<(std::ostream& out, const Animal& animal);

protected:
    std::string name_;
    std::string species_;
    int age_;
    Kind kind_;

private:
    static std::size_t totalCount_;
    static std::array<std::size_t, static_cast<std::size_t>(Kind::Count)> typeCounts_;
    static std::vector<Animal*> registry_;

    void registerSelf();
    void unregisterSelf() noexcept;
};
