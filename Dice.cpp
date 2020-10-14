#include "Dice.h"
#include <string>

Dice::Dice() {
    int index_table [] = {4,6,8,12,20};
    name = "test";
    index = 0;
    result = 0;
    hold = false;    
};

//Dice initialize -> dice size is based on the Dices class dice_list array index (int x), where the dices are generated
Dice::Dice(int x) {
    int index_table [] = {4,6,8,12,20};
    name = "D" + std::to_string(index_table[x]);
    index = index_table[x];
    result = 0;
    hold = false;
};


//For testing purposes only
void Dice::showAll(){
    std::cout << name << index << result << hold;
}

//Generates a random number based on dice index and inserts value to result
void Dice::throwDice() {
    if (hold == false) 
        result = (rand() % index + 1);        
};    

//Returns result
int Dice::getResult(){
    return result;
};

//Changes value for hold -parameter. False = rollabe, True = not rollabe
void Dice::changeHold(){
    if (hold = false)
        hold = true;
    else
        hold = false;
};

//Forces hold value to false
void Dice::releaseHold(){
    hold = false;
};

