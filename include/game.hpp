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

#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class Game {
public:
    explicit Game(const std::string& playerName);
    void start();

private:
    Player player;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text statusText;
    sf::Text menuText;
    sf::Text inputPromptText;

    void showWelcomeMessage();
    void render();
    void handleInput();
    void updateStatusText();
};

#endif //GAME_HPP