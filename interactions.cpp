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
void goblinFight(Player &player, Goblin &goblin , sf::RenderWindow &window)
{
    int turnOrder = 1;
    while(player.getPHp() > 0 || goblin.getEHp() > 0)
    {
        if(turnOrder == 1)
        {

            goblin.hpCheck();
            goblin.blockCheck();
            turnOrder = 2;
        }
        if(turnOrder == 2)
        {
            switch (goblin.makeDecision())
            {
            case 1:
                attack(player,goblin,turnOrder);
                break;
            case 2:
                goblin.eBlock();
                break;
            case 3:
                superAttack(player,goblin);
                break;
            default:
                break;
            }
            turnOrder = 1;
        }
        
    }
}

void superAttack(Player &player, Goblin &goblin)
{
    std::cout << "Enemy is Attacking" << std::endl;
        if(player.pHit(goblin.superAtt()) == true)
        {
            player.pDam(goblin.getEAtt()*2);
            std::cout << "Hit " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << goblin.getEHp() << std::endl;
        }
        else
        {
            std::cout <<"Miss " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << goblin.getEHp() << std::endl;
        }

}