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
#include <limits>
#include <cmath>

Player::Player(const std::string& name)
    : name(name), hp(100), level(1), xp(0), xpToNextLevel(100), credits(50), posX(0), posY(0) {}

void Player::updatePosition(int x, int y) {
    posX = x;
    posY = y;
}

void Player::gainXP(int amount) {
    constexpr int maxGain = std::numeric_limits<int>::max();

    int safeAmount = (amount > maxGain) ? maxGain : amount;
    xp += safeAmount;

    while (xp >= xpToNextLevel && level < 3333) {
        levelUp();
    }

    if (level == 3333 && xp >= xpToNextLevel) {
        xp = xpToNextLevel;
    }
}

void Player::levelUp() {
    xp -= xpToNextLevel;
    level++;

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