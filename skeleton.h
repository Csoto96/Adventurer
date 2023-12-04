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