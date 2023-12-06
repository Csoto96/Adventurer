/**
 * @file enemy.cpp
 * @author chris
 * @brief enemy functions file
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "enemy.h"
#include <chrono>
/**
 * @brief Construct a new Enemy:: Enemy object
 * 
 */
Enemy::Enemy()
{
    srand((unsigned) time(NULL));
    hp = 100;
    att = 10;
    armor = 10;
    blocking = false;
    name = "";
}
/**
 * @brief rolls to attack player minimum 1 
 * 
 * @return int 
 */
int Enemy::eAttack()
{
    int toHit = 1 + (rand() % 20);
    return toHit;
}
/**
 * @brief determines if enemy was hit by player
 * 
 * @param hit 
 * @return true 
 * @return false 
 */
bool Enemy::eHit(int hit)
{
    if(blocking == true)
    {
        blocking = false;
        return false;
    }
    if(hit >= armor)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief deals damage to enemy
 * 
 * @param damage 
 */
void Enemy::eDam(int damage)
{
    hp = hp - damage;
}
/**
 * @brief turns on blocking for enemy
 * 
 */
void Enemy::eBlock()
{
    blocking = true;
}
/**
 * @brief gets attack value for neutral functions
 * 
 * @return int 
 */
int Enemy::getEAtt()
{
    return att;
}
/**
 * @brief gets hp for resetting game
 * 
 * @return int 
 */
int Enemy::getEHp()
{
    return hp;
}
/**
 * @brief sets hp during game reset
 * 
 * @param num 
 */
void Enemy::setHp(int num)
{
    hp = num;
}