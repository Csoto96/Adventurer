#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>
#include <chrono>

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
            void update();
            void animationAttack();
            void setHp(int num);

            sf::Sprite p1;
            sf::Texture pArt;
            sf::Texture p1Attack, p1Dead, p1Win;
            sf::Clock clock;
            sf::IntRect rect;
            
    private:
            int hp;
            int att;
            int armor;
            bool blocking;
            std::string name;
            int frame;
            int isAttacking;
            
};
#endif