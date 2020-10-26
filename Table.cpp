#include "Table.h"
#include <iostream>
#include <sstream>
#include <string>  
using namespace std; 
    
    
Table::Table(){
    string table_names [19] = {};   
    string table_short [19] = {};
    string table_values [19] = {};
    bool isEnd = false;
}

//These table values could had been done better. I was thinking about making all of them objects,
//but then I decided to go with string lists. It felt easier...
//I feel like I would had needed to do same kind of work with these lists to initialize all the 19 objects, had I decided to go with objects
void Table::setTable(){
    string set_names [19]= {
        "(1) Ones            ",
        "(2) Twos            ",
        "(3) Threes          ",
        "(4) Fours           ",
        "(5) Fives           ",
        "(6) Sixes           ",
        "==Upper part bonus==",
        "(p1) One pair       ",
        "(p2) Two pairs      ",
        "(3s) Three same     ",
        "(4s) Four same      ",
        "(ls) Low straight   ",
        "(ms) Mid straight   ",
        "(hs) High straight  ",
        "(fh) Full house     ",
        "(sum) Sum           ",
        "(y) Yatzy           ",
        "===Lower part sum===",
        "Full table sum      "
    };
    string set_short [19] = {"1","2","3","4","5","6","","p1","p2","3s","4s","ls","ms","hs","fh","sum","y","",""};
    string set_values [19] = {"","","","","","","","","","","","","","","","","","",""};
    for (int i=0;i<19;i++){
        table_names[i] = set_names[i];
        table_short[i] = set_short[i];
        table_values[i] = set_values[i];
    }
    isEnd = false;

};


//Shows the table with added results (Called from Main() after every round)
void Table::showTable(){
    string text = "\nYatzy - Results table\n";
    for (int i = 0; i<19;i++){
        text += table_names[i] + " = " + table_values[i] + "\n";
    }
    cout << text << endl;
};

//Adds a result to a given name location. (Called from main())
//Gets parameters name_short, that is used to find correct index
//Second parameter result, is the added value
void Table::addResult(string name_short, string result){
    int index = -1;
    for (int i = 0;i < 19;i++){
        if (name_short == table_short[i])
            index = i;
    }
    if (index == -1 || index == 6)
        cout << "Invalid input" << endl;
    else
        table_values[index] = result;
};

//Checks if all table_values from 0 - 5 has been added -> counts upper part total (+ bonus) points
void Table::countUpper(){
    int sum=0;
    int is_valid = 1;
    
    for (int i = 0;i < 6; i++){
        if (table_values[i] == "")
            is_valid = 0;
        
        else {
            stringstream x(table_values[i]);
            int temp_value = 0;
            x >> temp_value;
            sum += temp_value;
        }
    }
    if (is_valid == 1){
        //if sum is negative -> no bonus
        if (sum >= 63)
            sum += 50;
        
        table_values[6] = to_string(sum);
    }
    
};
//Checks if all table_values from 7 - 16 has been added -> counts lower part total points
void Table::countLower(){
    int sum=0;
    int is_valid = 1;
    for (int i = 7;i < 17; i++){
        if (table_values[i] == "")
            is_valid = 0;
        else {
            stringstream x(table_values[i]);
            int temp_value = 0;
            x >> temp_value;
            sum += temp_value;
        }        
    }
    if (is_valid == 1){
        table_values[17] = to_string(sum);
    }
};

//if either upper part bonus or lower part sum equals "", then nothing.
//if both have values -> count final sum -> end game
void Table::countFinal(){
    if (!(table_values[6] == "" || table_values[17] == "")){
        stringstream x(table_values[6]);
        stringstream y(table_values[17]);
        int temp_value1 = 0;
        int temp_value2 = 0;
        x >> temp_value1;
        y >> temp_value2;
        table_values[18] = to_string(temp_value1 + temp_value2);
        isEnd = true;
    }
};

//If final score has been counted by countFinal() -> end game
void Table::checkGameEnd(){
    if (isEnd == true){
        showTable();
        cout << "***Game over - Your result was: " << table_values[18] << "***" << endl;
    }
};

void Table::endGame(){
    isEnd = true;
}

Table::~Table(){};
