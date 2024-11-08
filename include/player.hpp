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

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
public:
    explicit Player(const std::string& name); // Ensure the constructor is declared here

    void updatePosition(int x, int y);
    void gainXP(int amount);
    void levelUp();

    // Getter methods for rendering purposes in SFML
    const std::string& getName() const { return name; }
    int getHP() const { return hp; }
    int getLevel() const { return level; }
    int getXP() const { return xp; }
    int getXPToNextLevel() const { return xpToNextLevel; }
    int getCredits() const { return credits; }
    int getPosX() const { return posX; }
    int getPosY() const { return posY; }

private:
    std::string name;
    int hp;
    int level;
    int xp;
    int xpToNextLevel;
    int credits;
    int posX, posY;

    void updateXPThreshold();
};

int getSafeXPInput();

#endif //PLAYER_HPP