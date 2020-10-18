#pragma once
#include <iostream>
using namespace std;

class Table {
    public:
    string table_names [20];
    string table_short [20];
    string table_values [20];
    bool isEnd;
    bool upper_full;
    bool lower_full;

    public:
    Table();
    ~Table();
    void setTable();
    void showTable();
    void addResult(string name_short, string result);
    void countUpper();
    void countLower();
    void countFinal();
    void checkGameEnd();
    void endGame();
    
};
