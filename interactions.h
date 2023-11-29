#ifndef INTERACTIONS_H
#define INTERACTIONS_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "goblin.h"

void attack(Player &player,Enemy &enemy, int turn);
void changeTurn(int &turn);
void goblinFight(Player &player, Goblin &goblin,sf::RenderWindow &window);
void superAttack(Player &player, Goblin &goblin);
#endif