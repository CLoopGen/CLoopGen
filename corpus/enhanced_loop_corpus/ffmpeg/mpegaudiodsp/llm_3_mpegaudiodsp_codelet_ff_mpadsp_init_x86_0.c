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
            int offset = 4 * i;
            mdct_win_sse[0][j][offset]       = ff_mdct_win_float[j][i];
            mdct_win_sse[0][j][offset + 2]   = ff_mdct_win_float[j][i];
            mdct_win_sse[0][j][offset + 1]   = ff_mdct_win_float[j + 4][i];
            mdct_win_sse[0][j][offset + 3]   = ff_mdct_win_float[j + 4][i];
            mdct_win_sse[1][j][offset]       = ff_mdct_win_float[0][i];
            mdct_win_sse[1][j][offset + 2]   = ff_mdct_win_float[j][i];
            mdct_win_sse[1][j][offset + 1]   = ff_mdct_win_float[4][i];
            mdct_win_sse[1][j][offset + 3]   = ff_mdct_win_float[j + 4][i];
        }
    }
}
