#include "enemy.h"
#include <chrono>
Enemy::Enemy()
{
    srand((unsigned) time(NULL));
    hp = 100;
    att = 10;
    armor = 10;
    blocking = false;
    name = "";
}

// Enemy::~Enemy()
// {

// }

int Enemy::eAttack()
{
    int toHit = 1 + (rand() % 20);
    return toHit;
}

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

void Enemy::eDam(int damage)
{
    hp = hp - damage;
}

void Enemy::eBlock()
{
    blocking = true;
}

int Enemy::getEAtt()
{
    return att;
}

int Enemy::getEHp()
{
    return hp;
}

void Enemy::setHp(int num)
{
    hp = num;
}