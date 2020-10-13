#include "D12.h"

D12 :: D12() {
    result = 0;
}

void D12::throwDice12() {
    result = (rand() % 12 + 1);
};

