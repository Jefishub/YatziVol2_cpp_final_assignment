#include "Dices.h"
#include "Dice.h"
#include "Table.h"
#include "iostream"
using namespace std;



int main(){
    Dices nopat;
    Table taulukko;
    nopat.createDices();
    taulukko.setTable();
    //Start screen + fun extra
    cout << "Welcome to Yatzy vol 2" << endl << "Would you like to play?" << endl;
    cin.get();
    cout << "You don't have a choice now, do you ? Muahahaaa.." << endl;
    cout << "Press enter to play" << endl << endl;
    cin.get();
    while (taulukko.isEnd == false){
        taulukko.showTable();
        cout << endl;
        nopat.throwDices();
        nopat.showDices();
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
        cin.get();
        taulukko.checkGameEnd();

        cout << endl;
    }
    cout << "Good Game" << endl;
    cin.get();
    cout << "yes";
    

}
