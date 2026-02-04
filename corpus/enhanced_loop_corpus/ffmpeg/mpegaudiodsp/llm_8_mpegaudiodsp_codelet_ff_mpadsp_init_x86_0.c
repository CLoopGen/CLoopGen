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
    for (i = 0; i < 80; i += 2) {
        int idx = i >> 1;
        float val1 = ff_mdct_win_float[j][idx];
        float val2 = ff_mdct_win_float[j + 4][idx];
        mdct_win_sse[0][j][i]     = val1;
        mdct_win_sse[0][j][i + 1] = val2;
        mdct_win_sse[1][j][i]     = ff_mdct_win_float[0][idx];
        mdct_win_sse[1][j][i + 1] = ff_mdct_win_float[4][idx];
    }
}
}
