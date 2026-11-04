#pragma once
#include <array>
#include <cstddef>
#include <iosfwd>
#include <string>
#include <vector>

class Animal {
public:
    enum class Kind { Lion = 0, Elephant = 1, Parrot = 2, Bat = 3, Count = 4 };

    Animal(const std::string& name, const std::string& species, int age, Kind kind);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    virtual void makeSound() const = 0;
    virtual void move() const = 0;
    virtual std::string getSpecies() const = 0;

    // Виртуальная функция с реализацией по умолчанию.
    virtual void showBehavior() const;

    const std::string& getName() const noexcept;
    int getAge() const noexcept;
    Kind getKind() const noexcept;

    static std::size_t getTotalCount() noexcept;
    static std::size_t getCountByType(Kind kind) noexcept;
    static Animal* getOldestAnimal() noexcept;

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
