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
        //sf::Clock gClock;
        sf::Sprite gob;
        sf::Texture attArt, idleArt, deadArt, hitArt;
        
    private:
    bool isHurt;
    int eAttack();
            
};
#endif