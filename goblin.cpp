/**
 * @file goblin.cpp
 * @author chris/david
 * @brief goblin class functions
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "goblin.h"
/**
 * @brief Construct a new Goblin:: Goblin object
 * 
 */
Goblin::Goblin()
{
    srand((unsigned) time(NULL));
    hp = 30;
    att = 8;
    armor = 8;
    blocking = false;
    name = "Goblin";
    isHurt = false;
    if(!idleArt.loadFromFile("Monsters_Creatures_Fantasy/Goblin/Idle.png") ||
       !attArt.loadFromFile("Monsters_Creatures_Fantasy/Goblin/Attack.png") ||
       !deadArt.loadFromFile("Monsters_Creatures_Fantasy/Goblin/Death.png") ||
       !hitArt.loadFromFile("Monsters_Creatures_Fantasy/Goblin/Take_Hit.png"))
    {
        exit(1);
    }
    gob.setTexture(idleArt);
    gob.setTextureRect(sf::IntRect(0,0,150,150));
    gob.setOrigin(150.f/2.f,150.f/2.f);
    gob.setPosition(750,275);
    gob.setScale({-3,3});
}
/**
 * @brief rolls to hit using inheritance from enemy and returns int
 * 
 * @return int 
 */
int Goblin::eAttack()
{
    int store = Enemy::eAttack();
    return store;
}
/**
 * @brief determines what the goblin will do on its turn randomly 1 means attack, 2 means block, 3 means special
 * 
 * @return int 
 */
int Goblin::makeDecision()
{
    int turn = 1 + (rand() % 3);
    if(turn == 1 || (turn == 3 && isHurt == false))
    {
        return 1;
    }
    if(turn == 2)
    {
        return 1;
    }
    if(turn == 3 && isHurt == true)
    {
        return 3;
    }
    return 1;

}
/**
 * @brief super attack rolls to hit minimum of 3
 * 
 * @return int 
 */
int Goblin::superAtt()
{
    int toHit = 3 + (rand() % 20);
    return toHit;
}
/**
 * @brief checks goblin health to determine its panic mode (turns on special attack)
 * 
 */
void Goblin::hpCheck()
{
    if(hp <= 20)
    {
        isHurt = true;
    }
    else
    {
        isHurt = false;
    }
}
/**
 * @brief resets block to false if true so block isnt always on
 * 
 */
void Goblin::blockCheck()
{
    if(blocking == true)
    {
        blocking = false;
    }
}
/**
 * @brief was gunna be animation updater
 * 
 */
void Goblin::update()
{
    
}
