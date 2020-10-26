#include "Dices.h"
#include "Dice.h"
#include "Table.h"
#include "iostream"
#include <cstdio>


void clearScreen(){
    cout << string( 100, '\n' );
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
        cout << "Welcome to Yatzy vol 2" << endl << "Press any key + enter to play     (quit/exit -> to end program)" << endl;
        cin >> quit;
        if (quit == "quit" || quit == "exit"){
            end_game = true;
            break;
        }

        // runs until results in taulukko are full (or quit/exit command is given)
        while (taulukko.isEnd == false){

            //Dice throwing program - Loops back when player rolls dices (max 3 rolls)
            while (nopat.throws < 3){
                nopat.throwDices();
                taulukko.showTable();
                nopat.showDices();
                if (nopat.throws == 3)
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
                cout << "Mihin laitetaan ?";
                cin >> a;
                string b;
                cout << "Mikä tulos ?";
                cin >> b;
                taulukko.addResult(a,b);
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
