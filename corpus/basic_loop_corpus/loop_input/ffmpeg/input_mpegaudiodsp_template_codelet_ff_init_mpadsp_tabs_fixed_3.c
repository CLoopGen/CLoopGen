#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ff_mdct_win_fixed[8][40];
int i;
int j;

void init_vars() {
    for (int idx1 = 0; idx1 < 8; idx1++) {
        for (int idx2 = 0; idx2 < 40; idx2++) {
            ff_mdct_win_fixed[idx1][idx2] = rand() % 1000 - 500;
        }
    }
    i = 0;
    j = 0;
}