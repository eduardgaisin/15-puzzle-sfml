#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Util.hpp"
#include "Cell.hpp"

using std::vector;
using std::unique_ptr;

class Game {

public:
    Game(int board_size = 4);
    void update(const sf::Vector2i& pos);
    void render(sf::RenderWindow&);
    void shuffle();

private:
    void move(const sf::Vector2i& pos);
    sf::Vector2i blank_pos;
    int board_size;
    vector< vector< unique_ptr<Cell> > > board;
    std::shared_ptr<sf::Font> font;

};