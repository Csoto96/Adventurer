# Adventurer
Chris Soto, Noah Turner, and David Durrant
## Contribution:
Chris - Made enemys and player classes, game loop, win screen/deathscreen </br>
Noah - found usable sprites and sounds for game, made background and level transitions </br>
David - Made buttons and worked on animation
## How to play
All screens have buttons to click on, no keyboard needed, if game ever freezes for some unknown reason, ctrl+c on the console can get you out even if window X button wont </br>
You will have attack, block, and skill buttons to use </br>
Attack will attack the enemy </br>
Block will stop an enemy from hitting you </br>
Skill will heal you </br>
Simply defeat all enemies to win
## How to run the game 
Open the Ubuntu terminal </br>
Update the terminal </br>
sudo apt-get update && sudo apt-get upgrade -y </br>
Install the GNU compiler tools </br>
sudo apt-get install build-essential gdb </br>
Install git </br>
sudo apt-get install git </br>
Install SFML </br>
sudo apt-get install libsfml-dev </br>
Clone our repository </br>
git clone https://github.com/Csoto96/Adventurer.git foldername </br>
Change into directory </br>
cd foldername </br>
Compile our game </br>
```
g++ -std=c++11 *.cpp button/*.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
```
Run the executable </br>
./sfml-app
