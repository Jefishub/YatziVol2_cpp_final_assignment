#pragma once
#include <iostream>
using namespace std;

class Dice {
    public:
    int index_table[5];
    string name;
    int index;
    int result;
    bool hold;

    //constructors
    public:
    Dice(int x);
    void throwDice();
    int getResult();
    void setHold();
    void releaseHold();

};
