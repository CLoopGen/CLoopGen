#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ff_mdct_win_float[8][40];
extern __attribute__((aligned(16))) float mdct_win_sse[2][4][160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 2; j++) {
    for (i = 0; i < 40; i++) {
        float temp0_j_i = ff_mdct_win_float[j][i];
        float temp4_j_i = ff_mdct_win_float[j + 4][i];
        float temp0_0_i = ff_mdct_win_float[0][i];
        float temp4_4_i = ff_mdct_win_float[4][i];
        for (int k = 0; k < 2; k++) {
            int offset = 4 * i + 2 * k;
            mdct_win_sse[0][j + k][offset]     = temp0_j_i;
            mdct_win_sse[0][j + k][offset + 1] = temp4_j_i;
            mdct_win_sse[1][j + k][offset]     = temp0_0_i;
            mdct_win_sse[1][j + k][offset + 1] = temp4_4_i;
        }
    }
}
}
