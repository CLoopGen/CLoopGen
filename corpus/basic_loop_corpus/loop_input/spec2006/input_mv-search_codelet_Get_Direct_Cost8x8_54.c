#include <stdio.h>
#include <inttypes.h>

int i;
int j;
int k;
int curr_diff[8][8];
int diff8x8[64];

void init_vars() {
    i = 0;
    j = 0;
    k = 0;

    for (int jj = 0; jj < 8; ++jj) {
        for (int ii = 0; ii < 8; ++ii) {
            curr_diff[jj][ii] = (jj * 8 + ii) * 7; 
        }
    }

    for (int idx = 0; idx < 64; ++idx) {
        diff8x8[idx] = 0;
    }
}