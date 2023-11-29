#include "interactions.h"

void attack(Player &player,Enemy &enemy, int turn)
{
    //player turn
    if(turn == 1)
    {
        std::cout << "Player is Attacking" << std::endl;
        if(enemy.eHit(player.pAttack()) == true)
        {
            enemy.eDam(player.getPAtt());
            std::cout << "Hit " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << enemy.getEHp() << std::endl;
        }
        else
        {
            std::cout <<"Miss " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << enemy.getEHp() << std::endl;
        }
    }
    //enemy turn
    if(turn == 2)
    {
        std::cout << "Enemy is Attacking" << std::endl;
        if(player.pHit(enemy.eAttack()) == true)
        {
            player.pDam(enemy.getEAtt());
            std::cout << "Hit " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << enemy.getEHp() << std::endl;
        }
        else
        {
            std::cout <<"Miss " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << enemy.getEHp() << std::endl;
        }
    }
}

void changeTurn(int &turn)
{
    if(turn == 1)
    {
        turn = 2;
    }
    else
    {
        turn = 1;
    }
}