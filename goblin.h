#ifndef GOBLIN_H
#define GOBLIN_H
#include "enemy.h"

class Goblin: public Enemy
{
    public:
        Goblin();
        using Enemy::eAttack;
        sf::Sprite gob;
        sf::Texture attArt, idleArt, deadArt, hitArt;
        
    private:
    int eAttack();
            
};
#endif