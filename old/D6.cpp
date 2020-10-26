#include "D6.h"

D6 :: D6() {
    result = 0;
}

void D6::throwDice6() {
    result = (rand() % 6 + 1);
};

