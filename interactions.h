#ifndef INTERACTIONS_H
#define INTERACTIONS_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "goblin.h"
#include "skeleton.h"
#include "game.h"
#include "button/button.h"
#include "level.h"


void attack(Player &player,Enemy &enemy, int turn);
void goblinFight(Player &player, Goblin &goblin , Game &game, Button &abutton,Button &blbutton,Button &skbutton, int &currentScreen);
void skeletonFight(Player &player, Skeleton &skeleton , Game &game, Button &abutton,Button &blbutton,Button &skbutton, int &currentScreen);
void startScreen(Player &player, Game &game, Button &button, sf::Text &start, int &currentScreen);
void deathScreen(Player &player, Game &game, Button &rbutton,Button &ebutton, sf::Text &dead,int &currentScreen);
void winScreen(Player &player, Game &game, Button &rbutton,Button &ebutton, sf::Text &win,int &currentScreen);
void superAttack(Player &player, Goblin &goblin);
void superAttack(Player &player, Skeleton &skeleton);
void interlude(Level &level, Game &game);
#endif