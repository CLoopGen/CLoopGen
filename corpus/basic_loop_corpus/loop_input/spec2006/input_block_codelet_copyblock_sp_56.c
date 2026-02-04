#include <stdio.h>
#include <inttypes.h>

int i;
int j;
int i1;
int m5[4];
int predicted_block[4][4];

void init_vars() {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            predicted_block[i][j] = (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < 4; i++) {
        m5[i] = 0;
    }
    i = 0;
    j = 0;
    i1 = 0;
}