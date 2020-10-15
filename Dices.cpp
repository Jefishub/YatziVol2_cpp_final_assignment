#include "Dices.h"
#include <string>

//Initializing Dices class to create an empty Dice class array for your dices
Dices :: Dices() {
    Dice dice_list [5] = {};
    int throws = 0;
};

//Generates dices to dice_list array
void Dices::createDices(){
    for (int i = 0; i < 5; i++){
        Dice dice(i);
        dice_list[i] = dice;
    }
};

//Releases all dices to make them free for rerolling, resets throws counter
void Dices::releaseDices(){
    for (int i = 0; i < 5; i++){
        dice_list[i].releaseHold(); 
    }
    //throws = 0;
};

//Rolls dices -> new random value to Dice.result. Adds one throw to counter
void Dices::throwDices(){
    for (int j = 0; j < 5; j++){
        dice_list[j].throwDice();
    }
    //throws += 1;
};

//Generates text where dice size and results are shown -> return text
void Dices::showDices(){
    string text ="";
    for (int i = 0; i<5 ;i++){
        text += dice_list[i].name + " = " + std::to_string(dice_list[i].getResult()) + "\n";
    }
    cout << "---Dice throw results---" << endl << text << "---Dice throw results---" << endl;
};
