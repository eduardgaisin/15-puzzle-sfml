#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

struct Cell {

    Cell(int value, sf::Font* font) :
        value(value) {
        text.setFont(*font);
        text.setStyle(sf::Text::Bold);
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::Black);
        if (value == 0) {
            text.setString("");
            shape.setFillColor(sf::Color(100, 100, 100));
        } else {
            text.setString(std::to_string(value));
            shape.setFillColor(sf::Color(200, 200, 200));
        }
        shape.setSize(sf::Vector2f(CELL_SIZE.x - 1, CELL_SIZE.y - 1));
        shape.setOrigin(-0.5, -0.5);
    }

    int value;
    sf::Text text;
    sf::RectangleShape shape;

    void render(sf::RenderWindow& window, const sf::Vector2f& pos) {
        shape.setPosition(pos);
        window.draw(shape);
        text.setPosition(pos);
        window.draw(text);
    }

};