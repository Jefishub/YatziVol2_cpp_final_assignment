#include "D4.h"

D4::D4() {
    result = 0;
}

void D4::throwDice4() {
    result = (rand() % 4 + 1);
};
// END HERE
