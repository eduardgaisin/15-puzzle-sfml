#pragma once

#include <SFML/System.hpp>
#include <random>
#include <ctime>

const sf::Vector2f CELL_SIZE(40, 40);

// Generating x from [0; 1)
inline int randomInt2() {
    static std::uniform_int_distribution<int> distributionInt2(0, 1);
    static std::mt19937 generatorInt2(time(nullptr));
    return distributionInt2(generatorInt2);
}

// Generating x from [0; n-1]
inline int randomInt(int n) {
    static std::uniform_int_distribution<int> distribution(0, n * 1000 - 1);
    static std::mt19937 generator(time(nullptr));
    return distribution(generator) % n;
}