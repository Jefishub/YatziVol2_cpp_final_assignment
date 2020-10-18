#include "Dices.h"
#include "Dice.h"
#include "Table.h"
#include "iostream"
#include <cstdio>


void clearScreen(){
    cout << string( 100, '\n' );
}

void showInfo(){
    cout << "Yatzy vol 2 - RULES" << endl << endl
         << "In this version of yatzy you will have 5 dices, but all dices are different type.\n"
         << "You will have one D4, meaning dice with 4 edges or in other words you can get a result of 1 - 4.\n"
         << "With D6 you can get 1-6 and so on...\n"
         << "The full set of dices are D4, D6, D8, D12 and D20.\n\n"
         << "To roll dice -> write 'r' or 'roll'. \n"
         << "To hold a dice -> write 'h' and then select which dice to hold.\n"
         << "Select from 1 - 5 -> D4 = 1, D6 = 2, D8 = 3, D12 = 4 and D20 = 5.\n\n" 
         << "Selecting already holded dice will unhold that dice.\n"
         << "Selecting number 0 will change hold status of ALL dices.\n"
         << "Only non-holded dices will be rolled.\n\n"
         << "Each round you have maximum of 3 rolls.\n"
         << "After three rolls you have to select where you want your result.\n"
         << "See the Results Table for corresponding shortcut in parantheses in the beginning of every row.\n"
         << "Count the result and input that to the result table.\n\n"
         << "Write 'exit' or 'quit' to get back to main menu.\n\n"
         << "Have fun and good game!\n\n";
}

int main(){
    //create Dices and Table objects
    Dices nopat;
    Table taulukko;
    bool end_game = false;
    string quit = "";


    //Game program
    while (end_game == false){  

        //Set initial state for nopat and taulukko
        nopat.createDices();
        taulukko.setTable();

        //Start screen
        while (true){
        cout << "***Welcome to Yatzy vol 2***" << endl 
             << "write 'info' to see rules" << endl 
             << "write 'quit' or 'exit' to end program" << endl 
             << "Press any key + enter to play" << endl;
        cin >> quit;
        if (quit == "quit" || quit == "exit"){
            end_game = true;
            break;
        }
        else if (quit == "info"){
            showInfo();
            cin.get();
        }
        else
            break;
        }
        

        // runs until results in taulukko are full (or quit/exit command is given)
        while (taulukko.isEnd == false){

            //Dice throwing program - Loops back when player rolls dices (max 3 rolls)
            while (nopat.throws < 3){
                nopat.throwDices();
                taulukko.showTable();
                nopat.showDices();
                if (nopat.throws == 3) //Break out of while loop to input result into result table
                    break;
                else{

                    //Hold or roll -loop
                    while(true){
                        cout << "Hold ('h' / 'hold') or roll dices ('r' / 'roll'): ";
                        string str ="";
                        cin >> str;
                        if (str == "roll" || str == "r")
                            break;
                        else if (str == "quit" || str == "exit" || str == "end"){
                            taulukko.endGame();
                            nopat.throws = 3;
                            break;
                        }
                        else {
                            cout << "Select dice (1-5) or 0 -> Select all): ";
                            int hold_dice = 0;
                            cin >> hold_dice; //Must be integer between 0 - 5, -> 0 = All, 1-5 corresponding dice (Major issue if non integer given)
                            clearScreen();
                            nopat.holdDice(hold_dice);
                            taulukko.showTable();
                            nopat.showDices();
                        }

                    }
                }
                clearScreen();
            }
            if (taulukko.isEnd == false){
            //Add result to taulukko
                string a;
                cout << "Where to add ?";
                cin >> a;
                string b;
                cout << "What is result ?";
                cin >> b;
                taulukko.addResult(a,b); //a = string short_name, b = string result (value changed into integer in Table.addResult(a,b))
            }

            //Reset sequence. Counts upper and lower total, resets dices Hold to 0. Checks if taulukko is full -> game end
            nopat.releaseDices();       
            taulukko.countUpper();
            taulukko.countLower();
            taulukko.countFinal();
            taulukko.checkGameEnd();
            cout << endl;
        }
    }
}
