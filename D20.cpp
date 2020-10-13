#include "D20.h"

D20 :: D20() {
    result = 0;
}

void D20::throwDice20() {
    result = (rand() % 20 + 1);
};

