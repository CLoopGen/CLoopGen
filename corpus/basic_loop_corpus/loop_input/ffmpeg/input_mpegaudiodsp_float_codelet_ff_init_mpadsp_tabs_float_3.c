#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float ff_mdct_win_float[8][40];
int i;
int j;

void init_vars() {
    for (int idx1 = 0; idx1 < 8; idx1++) {
        for (int idx2 = 0; idx2 < 40; idx2++) {
            ff_mdct_win_float[idx1][idx2] = (float)(idx1 * 40 + idx2);
        }
    }
    i = 0;
    j = 0;
}