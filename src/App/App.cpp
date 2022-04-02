#include <iostream>

#include "App.hpp"

App::App(int board_size) : 
    window(new sf::RenderWindow(sf::VideoMode(CELL_SIZE.x * board_size, CELL_SIZE.y * board_size), "Game")),
    game(new Game(board_size)), current_index(-1, -1) {
    window->setKeyRepeatEnabled(false);
}

void App::run() {
    while (window->isOpen()) {
        event();
        update();
        render();
    }
}

void App::event() {
    sf::Event event;
    if (window->waitEvent(event)) {
        switch (event.type) {
            case sf::Event::MouseButtonPressed:
                current_index = sf::Mouse::getPosition(*window);
            break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::R) 
                    reshuffle = true;
            break;
            case sf::Event::Closed:
                window->close();
            break;
        }
    }
}

void App::update() {
    if (reshuffle) {
        game->shuffle();
        reshuffle = false;
    }
    if (current_index != sf::Vector2i(-1, -1)) {
        game->update(current_index);
        current_index = sf::Vector2i(-1, -1);
    }
}

void App::render() {
    window->clear(sf::Color(100, 200, 100));
    game->render(*window);
    window->display();
}
