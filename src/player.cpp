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

#include "player.hpp"
#include "colors.hpp"
#include <iostream>
#include <utility>
#include <limits>
#include <cmath>

Player::Player(std::string name)
    : name(std::move(name)), hp(100), level(1), xp(0), xpToNextLevel(100), credits(50), posX(0), posY(0) {}

void Player::showStatus() const {
    std::cout << BOLD << CYAN << "Player Status:\n" << RESET;
    std::cout << GREEN << "Name: " << name << RESET << "\n";
    std::cout << RED << "HP: " << hp << RESET << "\n";
    std::cout << YELLOW << "Level: " << level << RESET << "\n";
    std::cout << YELLOW << "XP: " << xp << "/" << xpToNextLevel << RESET << "\n";
    std::cout << BLUE << "Credits: " << credits << RESET << "\n";
    std::cout << MAGENTA << "Position: (" << posX << ", " << posY << ")" << RESET << "\n";
}

void Player::updatePosition(const int x, const int y) {
    posX = x;
    posY = y;
    std::cout << GREEN << "Position updated to (" << posX << ", " << posY << ")" << RESET << "\n";
}

void Player::gainXP(const int amount) {
    constexpr int maxGain = std::numeric_limits<int>::max();

    const int safeAmount = (amount > maxGain) ? maxGain : amount;

    xp += safeAmount;
    std::cout << YELLOW << "Gained " << safeAmount << " XP!" << RESET << "\n";

    while (xp >= xpToNextLevel && level < 3333) {
        levelUp();
    }

    if (level == 3333 && xp >= xpToNextLevel) {
        xp = xpToNextLevel;
        std::cout << RED << "Maximum level reached! You are at the cap of level 3333.\n" << RESET;
    }
}

int getSafeXPInput() {
    int amount;
    std::cin >> amount;

    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid integer.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return 0;
    }

    return amount;
}

void Player::levelUp() {
    xp -= xpToNextLevel;
    level++;
    std::cout << GREEN << "Congratulations! You've reached level " << level << "!" << RESET << "\n";

    constexpr int hpIncrease = 10;
    hp += hpIncrease;

    constexpr int maxHP = 999999999;
    if (hp > maxHP) {
        hp = maxHP;
    }

    updateXPThreshold();
}

void Player::updateXPThreshold() {
    constexpr int baseXP = 100;
    xpToNextLevel = static_cast<int>(std::round(baseXP * level * 1.5));
}