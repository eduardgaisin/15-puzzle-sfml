#include <iostream>

#include "Game.hpp"

Game::Game(int board_size) : board_size(board_size), font(new sf::Font()) {

    font->loadFromFile("arialmt.ttf");
    board.resize(board_size);
    for (int i = 0; i < board_size; i++) {
        board[i].resize(board_size);
        for (int j = 0; j < board_size; j++) {
            board[i][j].reset(new Cell(((i * board_size + j + 1 == board_size * board_size) ? 0 
                : (i * board_size + j + 1)), font.get()));
        }
    }
    blank_pos = sf::Vector2i(board_size - 1, board_size - 1);
}

void Game::update(const sf::Vector2i& pos) {
    sf::Vector2i cell_pos(pos.x / CELL_SIZE.x, pos.y / CELL_SIZE.y);
    move(cell_pos);
}

void Game::move(const sf::Vector2i& pos) {
    if (pos == blank_pos) return;
    if (pos.x == blank_pos.x) {
        if (pos.y > blank_pos.y) {
            for (int i = blank_pos.y; i < pos.y; i++) {
                board[i][pos.x].swap(board[i + 1][pos.x]);
            }
        } else {
            for (int i = blank_pos.y; i > pos.y; i--) {
                board[i][pos.x].swap(board[i - 1][pos.x]);
            }
        }
    } else if(pos.y == blank_pos.y) {
        if (pos.x > blank_pos.x) {
            for (int i = blank_pos.x; i < pos.x; i++) {
                board[pos.y][i].swap(board[pos.y][i + 1]);
            }
        } else {
            for (int i = blank_pos.x; i > pos.x; i--) {
                board[pos.y][i].swap(board[pos.y][i - 1]);
            }
        }
    } else {
        return;
    }
    blank_pos = pos;
}

void Game::render(sf::RenderWindow& window) {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            board[i][j]->render(window, sf::Vector2f(j * CELL_SIZE.x, i * CELL_SIZE.y));
        }
    }
}

void Game::shuffle() {
    for (int i = 0; i < 5000 * board_size; i++) {
        int side = randomInt2();
        if (side) {
            this->move(sf::Vector2i(blank_pos.x, randomInt(board_size)));
        } else {
            this->move(sf::Vector2i(randomInt(board_size), blank_pos.y));
        }
    }
}
