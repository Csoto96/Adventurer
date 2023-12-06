/**
 * @file skeleton.h
 * @author chris
 * @brief skeleton header class file
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SKELETON_H
#define SKELETON_H
#include "enemy.h"

class Skeleton: public Enemy
{
    public:
        Skeleton();
        using Enemy::eAttack;
        int makeDecision();
        int superAtt();
        void hpCheck();
        void blockCheck();
        sf::Sprite skele;
        sf::Texture attArt, idleArt, deadArt, hitArt;
        
    private:
    bool isHurt;
    int eAttack();
            
};
#endif