#pragma once
#include "Animal.h"
#include <memory>
#include <string>
#include <vector>

std::vector<std::unique_ptr<Animal>> loadAnimalsFromFile(const std::string& filename);
