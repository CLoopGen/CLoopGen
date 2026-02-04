#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ff_mdct_win_fixed[8][40];
int i;
int j;

void init_vars() {
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 40; i++) {
            ff_mdct_win_fixed[j][i] = rand() % 1000 - 500;
        }
    }
}