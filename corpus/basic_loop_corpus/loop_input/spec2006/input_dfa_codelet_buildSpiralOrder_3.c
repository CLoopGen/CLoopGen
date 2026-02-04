#include <stdint.h>

int generator[4] = {1, 2, 3, 4};

int mark[7056];

int fifo[14112];

int top;
int k;
int ii;
int delta;

void init_vars() {
    for (int i = 0; i < 7056; i++) {
        mark[i] = 0;
    }
    for (int i = 0; i < 14112; i++) {
        fifo[i] = 0;
    }
    top = 0;
    k = 0;
    ii = 100; // Choose ii such that ii + delta stays within [0, 7055]
    delta = 0;
}