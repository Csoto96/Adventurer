/**
 * @file enemy.h
 * @author chris
 * @brief enemy header clas file
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>

class Enemy
{
    public:
            Enemy();
            //~Enemy();
            virtual int eAttack();
            bool eHit(int hit);
            void eDam(int damage);
            void eBlock();
            int getEAtt();
            int getEHp();
            void setHp(int num);
    protected:
            int hp;
            int att;
            int armor;
            bool blocking;
            std::string name;
};
#endif