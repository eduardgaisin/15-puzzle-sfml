#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Game.hpp"
#include "Util.hpp"

using std::unique_ptr;

class App {

public:
    App(int board_size = 4);
    void run();

private:
    void event();
    void update();
    void render();
    void getIndex();

private:
    unique_ptr<sf::RenderWindow> window;
    unique_ptr<Game> game;
    sf::Vector2i current_index;
    bool reshuffle = false;
    
};