#include "goblin.h"

Goblin::Goblin()
{
    srand((unsigned) time(NULL));
    hp = 20;
    att = 10;
    armor = 10;
    blocking = false;
    name = "Goblin";
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
    gob.setPosition(250,200);
}

int Goblin::eAttack()
{
    Enemy::eAttack();
    gob.setTexture(attArt);
    gob.setTextureRect(sf::IntRect(0,0,150,150));
    gob.setOrigin(150.f/2.f,150.f/2.f);
    gob.setPosition(250,200);
}