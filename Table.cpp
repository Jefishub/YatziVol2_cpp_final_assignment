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
    bool upper_full = false;
    bool lower_full = false;
}

//These table values could had been done better. I was thinking about making all of them objects,
//but then I decided to go with string lists. It felt easier...
//I feel like I would had needed to do same kind of work with these lists to initialize all the 19 objects, had I decided to go with objects
void Table::setTable(){
    string set_names [20]= {
        "(1) Ones            ",
        "(2) Twos            ",
        "(3) Threes          ",
        "(4) Fours           ",
        "(5) Fives           ",
        "(6) Sixes           ",
        "===Upper part sum===",
        "**Upper part bonus**",
        "(1p) One pair       ",
        "(2p) Two pairs      ",
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
    string set_short [20] = {"1","2","3","4","5","6","","","1p","2p","3s","4s","ls","ms","hs","fh","sum","y","",""};
    string set_values [20] = {"","","","","","","","","","","","","","","","","","","",""};
    for (int i=0;i<20;i++){
        table_names[i] = set_names[i];
        table_short[i] = set_short[i];
        table_values[i] = set_values[i];
    }
    upper_full = false;
    lower_full = false;
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
    for (int i = 0;i < 18;i++){
        if (name_short == table_short[i])
            index = i;
    }
    if (index == -1 || index == 6 || index == 7)
        cout << "Invalid input" << endl;
    else
        table_values[index] = result;
};

//Checks if all table_values from 0 - 5 has been added -> counts upper part total (+ bonus) points
void Table::countUpper(){
    int sum=0;
    bool is_full = true;
    for (int i = 0;i < 6; i++){
        if (table_values[i] == "")
            is_full = false;        
        else {
            stringstream x(table_values[i]);
            int temp_value = 0;
            x >> temp_value;
            sum += temp_value;
        }
    }
    //if upper part is full
    if (is_full == true)
        upper_full = true;

    //if sum is less than 63 -> no bonus
    if (sum >= 63 & is_full == true)
        table_values[7] = 50;
    
    table_values[6] = to_string(sum);    
};
//Checks if all table_values from 7 - 16 has been added -> counts lower part total points
void Table::countLower(){
    int sum=0;
    bool is_full = true;
    for (int i = 8;i < 18; i++){
        if (table_values[i] != ""){
            stringstream x(table_values[i]);
            int temp_value = 0;
            x >> temp_value;
            sum += temp_value;
        }
        //if any value is "" -> is_full = false"
        else if (table_values[i] == "")
            is_full = false;        
    }

    //if lower part is full
    if (is_full == true)
        lower_full = true;

    table_values[18] = to_string(sum);
};

//if upper part sum or bonus or lower part sum has a value other than "" -> add the value to table_value[19] which is full table sum.
void Table::countFinal(){
    int sum = 0;
    if (!(table_values[6] == "")){
        stringstream x(table_values[6]);
        int temp_value1 = 0;
        x >> temp_value1;
        sum += temp_value1;
    }
    if (!(table_values[7] == "")){
        stringstream y(table_values[7]);
        int temp_value2 = 0;
        y >> temp_value2;
        sum += temp_value2;
    }
    if (!(table_values[18] == "")){
        stringstream z(table_values[18]);
        int temp_value3 = 0;
        z >> temp_value3;
        sum += temp_value3; 
    } 
          
    table_values[19] = to_string(sum);
    
};

//If final score has been counted by countFinal() -> end game
void Table::checkGameEnd(){
    if (upper_full == true & lower_full == true){
        isEnd = true;
        showTable();
        cout << "***Game over - Your result was: " << table_values[19] << "***" << endl;
    }
};

void Table::endGame(){
    isEnd = true;
};

Table::~Table(){};
