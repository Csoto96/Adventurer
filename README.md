# Adventurer
Chris Soto, Noah Turner, and David Durrant
Contribution:
Chris - Made enemys and player classes, game loop, win screen/deathscreen
Noah - found usable sprites and sounds for game, made background and level transitions
David - Made buttons and worked on animation
How to play
All screens have buttons to click on, no keyboard needed, if game ever freezes for some unknown reason, ctrl+c on the console can get you out even if window X button wont
you will have attack, block, and skill buttons simply defeat all enemies to win
How to run the game
Open the Ubuntu terminal
Update the terminal
sudo apt-get update && sudo apt-get upgrade -y
Install the GNU compiler tools
sudo apt-get install build-essential gdb
Install git
sudo apt-get install git
Install SFML
sudo apt-get install libsfml-dev
Clone our repository
git clone https://github.com/Csoto96/Adventurer.git <foldername>
Change into directory
cd <foldername>
Compile our game
g++ -std=c++11 *.cpp button/*.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
Run the executable
./sfml-app
