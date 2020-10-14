#include "Dice.h"

Dice::Dice(int x) {
    int index_table [] = {4,6,8,12,20};
    name = "D" + index_table[x];
    index = index_table[x];
    result = 0;
    hold = false;
};

void Dice::throwDice() {
    if (hold == false) 
        result = (rand() % index + 1);        
};    

int Dice::getResult(){
    return result;
};
 
void Dice::setHold(){
    hold = true;
};
void Dice::releaseHold(){
    hold = false;
};

