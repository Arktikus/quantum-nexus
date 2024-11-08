/*
 * Copyright (C) 2024 Arktikus
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "game.hpp"
#include <iostream>

Game::Game(const std::string& playerName)
    : player(playerName), window(sf::VideoMode(800, 600), "Space Adventure Game") {

    // Load font for displaying text
    if (!font.loadFromFile("path/to/your/font.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    // Setup status text
    statusText.setFont(font);
    statusText.setCharacterSize(20);
    statusText.setFillColor(sf::Color::White);
    updateStatusText();

    // Setup menu text
    menuText.setFont(font);
    menuText.setCharacterSize(20);
    menuText.setFillColor(sf::Color::Yellow);
    menuText.setString("1 - Show player status\n2 - Update position\n3 - Gain XP\n0 - Exit");
    menuText.setPosition(20, 300);
}

void Game::start() {
    showWelcomeMessage();
    while (window.isOpen()) {
        handleInput();
        render();
    }
}

void Game::showWelcomeMessage() {
    statusText.setString("Welcome to the Space Adventure Game!\nYou are a space explorer, ready to conquer the universe.");
    statusText.setPosition(20, 20);
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Num1:
                    updateStatusText();
                    break;
                case sf::Keyboard::Num2:
                    player.updatePosition(player.getPosX() + 10, player.getPosY() + 10);
                    updateStatusText();
                    break;
                case sf::Keyboard::Num3:
                    player.gainXP(100);
                    updateStatusText();
                    break;
                case sf::Keyboard::Num0:
                    window.close();
                    break;
                default:
                    break;
            }
        }
    }
}

void Game::updateStatusText() {
    statusText.setString("Player Status:\n" +
                         player.getName() + "\nHP: " +
                         std::to_string(player.getHP()) + "\nLevel: " +
                         std::to_string(player.getLevel()) + "\nXP: " +
                         std::to_string(player.getXP()) + "/" + std::to_string(player.getXPToNextLevel()));
    statusText.setPosition(20, 20);
}

void Game::render() {
    window.clear();
    window.draw(statusText);
    window.draw(menuText);
    window.display();
}