#include <stdio.h>
#include <inttypes.h>

int i;
int j;
int _usr_j1;
int m5[4];
int predicted_block[4][4];

void init_vars() {
    for (int idx_i = 0; idx_i < 4; idx_i++) {
        for (int idx_j = 0; idx_j < 4; idx_j++) {
            predicted_block[idx_i][idx_j] = (idx_i * 4 + idx_j) % 17;
        }
    }
    for (int idx = 0; idx < 4; idx++) {
        m5[idx] = 0;
    }
    i = 0;
    j = 0;
    _usr_j1 = 0;
}