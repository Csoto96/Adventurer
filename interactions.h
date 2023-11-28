#ifndef INTERACTIONS_H
#define INTERACTIONS_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"

void attack(Player &player,Enemy &enemy, int turn);
void changeTurn(int &turn);
#endif