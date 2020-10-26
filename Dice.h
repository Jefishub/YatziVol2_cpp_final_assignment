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
    Dice();
    Dice(int x);
    ~Dice();
    void showAll();

    void throwDice();
    int getResult();
    void changeHold();
    void releaseHold();

};
