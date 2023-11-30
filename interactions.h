#ifndef INTERACTIONS_H
#define INTERACTIONS_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "goblin.h"
#include "game.h"

void attack(Player &player,Enemy &enemy, int turn);
void goblinFight(Player &player, Goblin &goblin,Game &game);
void startScreen(Player &player, Game &game);
void superAttack(Player &player, Goblin &goblin);
#endif