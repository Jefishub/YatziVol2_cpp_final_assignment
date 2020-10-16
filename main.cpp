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
    //Start screen + fun extra
    cout << "Welcome to Yatzy vol 2" << endl << "Would you like to play?" << endl;
    cin.get();
    cout << "You don't have a choice now, do you ? Muahahaaa.." << endl;
    cout << "Press enter to play" << endl << endl;
    cin.get();
    //Game program
    while (taulukko.isEnd == false){
        taulukko.showTable();
        cout << endl;

        while (nopat.throws < 3){
            nopat.throwDices();
            taulukko.showTable();
            nopat.showDices();
            if (nopat.throws == 3)
                break;
            else{
                while(true){
                    cout << "Hold ('h' / 'hold') or roll dices ('r' / 'roll'): ";
                    string str ="";
                    cin >> str;
                    if (str == "roll" || str == "r")
                        break;
                    cout << "Select dice (1-5): ";
                    int hold_dice = 0;
                    cin >> hold_dice;
                    nopat.holdDice(hold_dice-1);
                }
            }
        }
        nopat.releaseDices();
        string a;
        cout << "Mihin laitetaan ?";
        cin >> a;
        string b;
        cout << "Mikä tulos ?";
        cin >> b;
        taulukko.addResult(a,b);        
        taulukko.countUpper();
        taulukko.countLower();
        taulukko.countFinal();
        taulukko.checkGameEnd();
        cout << endl;
    }
    cout << endl << "Good Game" << endl;
    cin.get();
    cout << "yes";
    

}
