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
#include "colors.hpp"
#include <iostream>

Game::Game(std::string playerName) : player(std::move(playerName)) {}

void Game::start() {
    showWelcomeMessage();
    player.showStatus();
    int choice;

    do {
        showMenu();
        std::cout << "Choose an action: ";
        std::cin >> choice;
        handleInput(choice);
    } while (choice != 0);

    std::cout << "Exiting the game. Goodbye!\n";
}

void Game::showWelcomeMessage() {
    std::cout << BOLD << CYAN << "Welcome to the Space Adventure Game!" << RESET << "\n";
    std::cout << "You are a space explorer, ready to conquer the universe.\n";
    std::cout << YELLOW << "Current Status:\n" << RESET;
}

void Game::showMenu() {
    std::cout << "\n--- Game Menu ---\n";
    std::cout << "1 - Show player status\n";
    std::cout << "2 - Update position\n";
    std::cout << "3 - Gain XP\n";
    std::cout << "0 - Exit\n";
}

void Game::handleInput(const int choice) {
    switch (choice) {
        case 1:
            player.showStatus();
        break;
        case 2: {
            int x, y;
            std::cout << "Enter new X position: ";
            std::cin >> x;
            std::cout << "Enter new Y position: ";
            std::cin >> y;
            player.updatePosition(x, y);
            break;
        }
        case 3: {
            std::cout << "Enter XP to gain: ";
            const int xp = getSafeXPInput();
            player.gainXP(xp);
            break;
        }
        case 0:
            std::cout << "Preparing to exit the game.\n";
        break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        break;
    }
}