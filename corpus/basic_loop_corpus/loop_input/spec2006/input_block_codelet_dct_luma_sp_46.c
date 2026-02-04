#include <stdio.h>
#include <inttypes.h>

int i;
int j;
int _usr_j1;
int m5[4];
int predicted_block[4][4];

void init_vars() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            predicted_block[i][j] = (i * 4 + j) + 1;
        }
    }
    for (int j = 0; j < 4; j++) {
        m5[j] = 0;
    }
    i = 0;
    j = 0;
    _usr_j1 = 0;
}