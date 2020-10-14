#include "Dices.h"
#include <string>

Dices :: Dices() {
    Dice dice_list [5] = {};
};

void Dices::createDices(){
    for (int i = 0; i < 5; i++){
        Dice dice(i);
        dice_list[i] = dice;
    }
};

void Dices::releaseDices(){
    for (int i = 0; i < 5; i++){
        dice_list[i].releaseHold(); 
    }
};

void Dices::throwDices(){
    for (int j = 0; j < 5; j++){
        dice_list[j].throwDice();
    }
};

string Dices::showDices(){
    string text ="";
    for (int i = 0; i<5 ;i++){
        text += dice_list[i].name + " = " + std::to_string(dice_list[i].getResult()) + "\n";
    }
    return text;
};
