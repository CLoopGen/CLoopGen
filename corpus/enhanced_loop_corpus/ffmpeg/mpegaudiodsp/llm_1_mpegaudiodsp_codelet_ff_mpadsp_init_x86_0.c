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
            float temp1 = ff_mdct_win_float[j][i];
            float temp2 = ff_mdct_win_float[j + 4][i];
            float temp3 = ff_mdct_win_float[0][i];
            float temp4 = ff_mdct_win_float[4][i];
            for (int k = 0; k < 4; k += 2) {
                mdct_win_sse[0][j][base_idx + k] = temp1;
                mdct_win_sse[0][j][base_idx + k + 1] = temp2;
                mdct_win_sse[1][j][base_idx + k] = (k == 0) ? temp3 : temp1;
                mdct_win_sse[1][j][base_idx + k + 1] = (k == 0) ? temp4 : temp2;
            }
        }
    }
}
