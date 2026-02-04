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
    float temp1[4][40];
    float temp2[4][40];
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 40; i++) {
            temp1[j][i] = ff_mdct_win_float[j][i];
            temp2[j][i] = ff_mdct_win_float[j + 4][i];
        }
    }
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 40; i++) {
            mdct_win_sse[0][j][4 * i] = temp1[j][i];
            mdct_win_sse[0][j][4 * i + 1] = temp2[j][i];
            mdct_win_sse[0][j][4 * i + 2] = temp1[j][i];
            mdct_win_sse[0][j][4 * i + 3] = temp2[j][i];
            mdct_win_sse[1][j][4 * i] = temp1[0][i];
            mdct_win_sse[1][j][4 * i + 1] = temp2[0][i];
            mdct_win_sse[1][j][4 * i + 2] = temp1[j][i];
            mdct_win_sse[1][j][4 * i + 3] = temp2[j][i];
        }
    }
}
