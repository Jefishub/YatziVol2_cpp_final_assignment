#include "Dices.h"
#include "Dice.h"
#include "Table.h"
#include "iostream"
using namespace std;




int main(){
    //create Dices and Table objects
    Dices nopat;
    Table taulukko;

    //Set initial state for nopat and taulukko
    nopat.createDices();
    taulukko.setTable();

    //Start screen + "fun" extra
    cout << "Welcome to Yatzy vol 2" << endl << "Would you like to play?" << endl;
    cin.get();
    cout << "You don't have a choice now, do you ? Muahahaaa.." << endl;
    cout << "Press enter to play" << endl << endl;
    cin.get();

    //Game program - runs until results in taulukko are full
    while (taulukko.isEnd == false){
        taulukko.showTable();
        cout << endl;

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
                    cout << "Select dice (1-5) or 0 -> Select all): ";
                    int hold_dice = 0;
                    cin >> hold_dice; //Must be integer between 0 - 5, -> 0 = All, 1-5 corresponding dice
                    nopat.holdDice(hold_dice);
                    taulukko.showTable();
                    nopat.showDices();
                }
            }
        }

        //Add result to taulukko
        string a;
        cout << "Mihin laitetaan ?";
        cin >> a;
        string b;
        cout << "Mikä tulos ?";
        cin >> b;
        taulukko.addResult(a,b);

        //Reset sequence. Counts upper and lower total, resets dices Hold to 0. Checks if taulukko is full -> game end
        nopat.releaseDices();       
        taulukko.countUpper();
        taulukko.countLower();
        taulukko.countFinal();
        taulukko.checkGameEnd();
        cout << endl;
    }

    //Game end screen
    cout << endl << "Good Game" << endl;
    cin.get();
    cout << "yes";
    

}
