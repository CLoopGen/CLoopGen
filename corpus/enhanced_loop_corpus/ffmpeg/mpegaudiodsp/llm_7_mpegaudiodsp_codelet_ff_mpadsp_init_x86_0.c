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
    for (i = 0; i < 40; i++) {
        for (j = 0; j < 4; j++) {
            float val_j_i = ff_mdct_win_float[j][i];
            float val_j4_i = ff_mdct_win_float[j + 4][i];
            float val_0_i = ff_mdct_win_float[0][i];
            float val_4_i = ff_mdct_win_float[4][i];
            mdct_win_sse[0][j][4 * i] = val_j_i;
            mdct_win_sse[0][j][4 * i + 1] = val_j4_i;
            mdct_win_sse[0][j][4 * i + 2] = val_j_i;
            mdct_win_sse[0][j][4 * i + 3] = val_j4_i;
            mdct_win_sse[1][j][4 * i] = val_0_i;
            mdct_win_sse[1][j][4 * i + 1] = val_4_i;
            mdct_win_sse[1][j][4 * i + 2] = val_j_i;
            mdct_win_sse[1][j][4 * i + 3] = val_j4_i;
        }
    }
}
