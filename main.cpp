#include "Dices.h"
#include "Dice.h"
#include "iostream"
using namespace std;



int main(){
    cout << "This is a test1" << endl;
    Dices nopat;
    nopat.createDices();
    cout << nopat.showDices();
    nopat.throwDices();
    cout << nopat.showDices();
    cin.get();
    

}
