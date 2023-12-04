#include "goblin.h"

Goblin::Goblin()
{
    srand((unsigned) time(NULL));
    hp = 30;
    att = 8;
    armor = 8;
    blocking = false;
    name = "Goblin";
    isHurt = false;
    if(!idleArt.loadFromFile("Monsters_Creatures_Fantasy/Goblin/Idle.png") ||
       !attArt.loadFromFile("Monsters_Creatures_Fantasy/Goblin/Attack.png") ||
       !deadArt.loadFromFile("Monsters_Creatures_Fantasy/Goblin/Death.png") ||
       !hitArt.loadFromFile("Monsters_Creatures_Fantasy/Goblin/Take_Hit.png"))
    {
        exit(1);
    }
    gob.setTexture(idleArt);
    gob.setTextureRect(sf::IntRect(0,0,150,150));
    gob.setOrigin(150.f/2.f,150.f/2.f);
    gob.setPosition(750,275);
    gob.setScale({-3,3});
}

int Goblin::eAttack()
{
    int store = Enemy::eAttack();
    // int frameCount = 1;
    // gob.setTexture(attArt);
    // gob.setTextureRect(sf::IntRect(0,0,150,150));
    // gob.setOrigin(150.f/2.f,150.f/2.f);
    // gob.setPosition(750,300);
    // while(frameCount < 9)
    // {
    //     gob.setTextureRect(sf::IntRect(0+150*frameCount,0+150*frameCount,150,150));
    //     frameCount++;
    // }
    return store;
}
int Goblin::makeDecision()
{
    int turn = 1 + (rand() % 3);
    if(turn == 1 || (turn == 3 && isHurt == false))
    {
        return 1;
    }
    if(turn == 2)
    {
        return 1;
    }
    if(turn == 3 && isHurt == true)
    {
        return 3;
    }
    return 1;

}

int Goblin::superAtt()
{
    int toHit = 3 + (rand() % 20);
    std::cout << "rolled " << toHit << std::endl;
    return toHit;
}

void Goblin::hpCheck()
{
    if(hp <= 20)
    {
        isHurt = true;
    }
    else
    {
        isHurt = false;
    }
}

void Goblin::blockCheck()
{
    if(blocking == true)
    {
        blocking = false;
    }
}
