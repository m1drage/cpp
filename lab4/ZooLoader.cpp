/**
 * @file ZooLoader.cpp
 * @brief Реализация загрузчика животных.
 * @details Читает данные из файла и создаёт объекты
 * соответствующих классов животных.
 */

#include "ZooLoader.h"
#include "Lion.h"
#include "Elephant.h"
#include "Parrot.h"
#include "Bat.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<std::unique_ptr<Animal>> loadAnimalsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) throw std::runtime_error("Could not open file: " + filename);

    std::vector<std::unique_ptr<Animal>> animals;
    std::string line;
    std::size_t lineNumber = 0;

    while (std::getline(file, line)) {
        ++lineNumber;
        if (line.empty() || line[0] == '#') continue;

        // Format: type|name|age|gestationPeriod|nursing|wingspan|canFly
        std::istringstream in(line);
        std::string type, name, ageText, gestationText, nursingText, wingspanText, canFlyText;
        if (!std::getline(in, type, '|') || !std::getline(in, name, '|') ||
            !std::getline(in, ageText, '|') || !std::getline(in, gestationText, '|') ||
            !std::getline(in, nursingText, '|') || !std::getline(in, wingspanText, '|') ||
            !std::getline(in, canFlyText)) {
            throw std::runtime_error("Invalid format at line " + std::to_string(lineNumber));
        }

        try {
            int age = std::stoi(ageText);
            int gestation = std::stoi(gestationText);
            bool nursing = std::stoi(nursingText) != 0;
            double wingspan = std::stod(wingspanText);
            bool canFly = std::stoi(canFlyText) != 0;

            if (type == "Lion")
                animals.push_back(std::make_unique<Lion>(name, age, gestation, nursing));
            else if (type == "Elephant")
                animals.push_back(std::make_unique<Elephant>(name, age, gestation, nursing));
            else if (type == "Parrot")
                animals.push_back(std::make_unique<Parrot>(name, age, wingspan, canFly));
            else if (type == "Bat")
                animals.push_back(std::make_unique<Bat>(name, age, gestation, nursing, wingspan, canFly));
            else
                throw std::runtime_error("Unknown animal type: " + type);
        } catch (const std::exception& e) {
            throw std::runtime_error("Error at line " + std::to_string(lineNumber) + ": " + e.what());
        }
    }
    return animals;
}
