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
            int eAttack();
            bool eHit(int hit);
            void eDam(int damage);
            void eBlock();
            int getEAtt();
            int getEHp();
    protected:
            int hp;
            int att;
            int armor;
            bool blocking;
            std::string name;
};
#endif