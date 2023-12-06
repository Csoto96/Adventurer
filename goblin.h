/**
 * @file goblin.h
 * @author chris/david
 * @brief goblin header file
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef GOBLIN_H
#define GOBLIN_H
#include "enemy.h"

class Goblin: public Enemy
{
    public:
        Goblin();
        using Enemy::eAttack;
        int makeDecision();
        int superAtt();
        void hpCheck();
        void blockCheck();
        void update();
        sf::IntRect rect;
        sf::Clock clock;
        sf::Sprite gob;
        sf::Texture attArt, idleArt, deadArt, hitArt;
        void animationAttack();
        
    private:
    int isAttacking;
    bool isHurt;
    int eAttack();
            
};
#endif