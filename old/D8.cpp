#include "D8.h"

D8 :: D8() {
    result = 0;
}

void D8::throwDice8() {
    result = (rand() % 8 + 1);
};

