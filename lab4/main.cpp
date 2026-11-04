/**
 * @file main.cpp
 * @brief Главная программа лабораторной работы.
 * @details Демонстрирует работу классов животных,
 * наследование, полиморфизм и подсчёт статистики.
 */

#include "ZooLoader.h"
#include "Lion.h"
#include "Elephant.h"
#include "Parrot.h"
#include "Bat.h"
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>


static void printStatistics() {
    using K = Animal::Kind;
    std::cout << "\n--- Animal statistics ---\n"
              << "Total objects: " << Animal::getTotalCount() << '\n'
              << "Lions: " << Animal::getCountByType(K::Lion) << '\n'
              << "Elephants: " << Animal::getCountByType(K::Elephant) << '\n'
              << "Parrots: " << Animal::getCountByType(K::Parrot) << '\n'
              << "Bats: " << Animal::getCountByType(K::Bat) << '\n';
}

int main(int argc, char* argv[]) {
    const std::string dataFile = (argc > 1) ? argv[1] : "animals.txt";

    try {
        auto animals = loadAnimalsFromFile(dataFile);

        std::cout << "Objects loaded from file: " << animals.size() << "\n\n";

        
        std::cout << "--- Polymorphic behavior ---\n";
        for (const auto& animal : animals) {
            std::cout << *animal << '\n';
            animal->makeSound();
            animal->move();
            animal->showBehavior();
            std::cout << "-----------------------------\n";
        }

        
        std::vector<Animal*> enclosure;
        for (const auto& animal : animals) enclosure.push_back(animal.get());
        std::cout << "\nAnimals in enclosure: " << enclosure.size() << " animals.\n";

        
        for (Animal* animal : enclosure) {
            if (auto* bat = dynamic_cast<Bat*>(animal)) {
                Mammal* mammalPart = bat;
                Bird* birdPart = bat;
                Animal* animalFromMammal = mammalPart;
                Animal* animalFromBird = birdPart;
                std::cout << "\nBat check: " << bat->getName()
                          << "\nSingle Animal base subobject: "
                          << std::boolalpha << (animalFromMammal == animalFromBird)
                          << "\nGestation period: " << mammalPart->getGestationPeriod()
                          << "\nWingspan: " << birdPart->getWingspan() << " m\n";
            }
        }

        
        std::cout << "\n--- Copy test ---\n";
        Lion original("TestLion", 8, 110, true);
        Lion copied(original);                  
        copied = Lion("OtherLion", 5, 105, false); 
        std::cout << "Original: " << original << '\n';
        std::cout << "Copy after modification: " << copied << '\n';
        std::cout << "Independent strings: "
                  << (original.getName() != copied.getName()) << '\n';

        Bat batOriginal("TestBat", 4, 50, true, 0.4, true);
        Bat batCopy(batOriginal);
        batCopy = batOriginal;
        std::cout << "Bat copy: " << batCopy << '\n';

        
        Animal* oldest = Animal::getOldestAnimal();
        if (oldest) std::cout << "\nOldest animal: " << *oldest << '\n';

        printStatistics();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    std::cout << "\nTesting completed.\n";
    return 0;
}
