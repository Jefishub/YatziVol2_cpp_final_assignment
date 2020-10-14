#include "Dice.h"
#include <string>

Dice::Dice() {
    int index_table [] = {4,6,8,12,20};
    name = "test";
    index = 0;
    result = 0;
    hold = false;    
};

Dice::Dice(int x) {
    int index_table [] = {4,6,8,12,20};
    name = "D" + std::to_string(index_table[x]);
    index = index_table[x];
    result = 0;
    hold = false;
};
void Dice::showAll(){
    std::cout << name << index << result << hold;
}
//void Dice::setDices(int index){
//    int index_table [] = {4,6,8,12,20};
//    name = "D" + std::to_string(index_table[index]);
//}

void Dice::throwDice() {
    if (hold == false) 
        result = (rand() % index + 1);        
};    

int Dice::getResult(){
    return result;
};
 
void Dice::changeHold(){
    if (hold = false)
        hold = true;
    else
        hold = false;
};
void Dice::releaseHold(){
    hold = false;
};

