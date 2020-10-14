#include "Dices.h"
#include "Dice.h"
#include "Table.h"
#include "iostream"
using namespace std;



int main(){
    cout << "This is a test1" << endl;
    Dices nopat;
    Table taulukko;
    nopat.createDices();
    cout << nopat.showDices();
    taulukko.showTable();
    nopat.throwDices();
    cout << nopat.showDices();
    cin.get();
    

}
