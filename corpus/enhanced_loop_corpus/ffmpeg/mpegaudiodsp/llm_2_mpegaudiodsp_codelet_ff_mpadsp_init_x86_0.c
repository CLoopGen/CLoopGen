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
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 40; i++) {
            int base_idx = 4 * i;
            float val1 = ff_mdct_win_float[j][i];
            float val2 = ff_mdct_win_float[j + 4][i];
            float val3 = ff_mdct_win_float[0][i];
            float val4 = ff_mdct_win_float[4][i];
            mdct_win_sse[0][j][base_idx]     = val1;
            mdct_win_sse[0][j][base_idx + 1] = val2;
            mdct_win_sse[0][j][base_idx + 2] = val1;
            mdct_win_sse[0][j][base_idx + 3] = val2;
            mdct_win_sse[1][j][base_idx]     = val3;
            mdct_win_sse[1][j][base_idx + 1] = val4;
            mdct_win_sse[1][j][base_idx + 2] = val1;
            mdct_win_sse[1][j][base_idx + 3] = val2;
        }
    }
}
