#include "Dices.h"
#include "iostream"
using namespace std;



int main(){
    D4 noppa4;
    D6 noppa6;
    D8 noppa8;
    while (true){
        noppa8.throwDice8();
        cout << noppa8.result;
        cin.get();
    }
    
    noppa4.throwDice4();
    cout << noppa4.result << endl;
    noppa6.throwDice6();
    cout << noppa6.result << endl;
    


}
