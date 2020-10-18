#include "Dice.h"
#include <string>
#include <cstdlib>
#include <ctime>

Dice::Dice() {
    int index_table [] = {4,6,8,12,20};
    name = "test";
    index = 0;
    result = 0;
    hold = 0;    
};

//Dice initialize -> dice size is based on the Dices class dice_list array index (int x), where the dices are generated
Dice::Dice(int x) {
    int index_table [] = {4,6,8,12,20};
    name = "D" + std::to_string(index_table[x]);
    index = index_table[x];
    result = 0;
    hold = 0;
};


//For testing purposes only
void Dice::showAll(){
    std::cout << "name:"<< name <<"index:" << index << "result:" << result << "hold:" << hold << endl;
}

//Generates a random number based on dice index and inserts value to result
void Dice::throwDice() {
    srand((unsigned int)time(NULL)); //Fixes problem with pseudorandom number generator
    if (hold == 0) 
        result = (rand() % index + 1);        
};    

//Returns result
int Dice::getResult(){
    return result;
};

//Changes value for hold -parameter. False = rollabe, True = not rollabe
void Dice::changeHold(){
    if (hold == 0)
        hold = 1;
    else
        hold = 0;
};

//Forces hold value to false
void Dice::releaseHold(){
    hold = 0;
};

Dice::~Dice(){};