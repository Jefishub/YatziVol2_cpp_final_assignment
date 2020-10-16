#pragma once
#include <iostream>
using namespace std;

class Table {
    public:
    string table_names [19];
    string table_short [19];
    string table_values [19];
    bool isEnd;

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
    
};
