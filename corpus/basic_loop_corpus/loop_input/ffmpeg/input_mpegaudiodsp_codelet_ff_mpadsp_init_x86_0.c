#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float ff_mdct_win_float[8][40];

__attribute__((aligned(16))) float mdct_win_sse[2][4][160];

int i;
int j;

void init_vars() {
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 40; i++) {
            ff_mdct_win_float[j][i] = (float)(j * 40 + i + 1);
        }
    }

    for (int k = 0; k < 2; k++) {
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 160; i++) {
                mdct_win_sse[k][j][i] = 0.0f;
            }
        }
    }

    i = 0;
    j = 0;
}