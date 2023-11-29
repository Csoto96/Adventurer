#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>

class Player
{
    public:
            Player();
            int pAttack();
            bool pHit(int hit);
            void pDam(int damage);
            void pBlock();
            int getPAtt();
            int getPHp();
            void blockCheck();
            void skillHeal();

            sf::Sprite p1;
            sf::Texture pArt;
    private:
            int hp;
            int att;
            int armor;
            bool blocking;
            std::string name;
};
#endif