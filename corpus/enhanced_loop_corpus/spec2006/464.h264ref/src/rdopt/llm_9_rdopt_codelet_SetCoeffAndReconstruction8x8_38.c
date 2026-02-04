#include <stdio.h>

#include <inttypes.h>

extern int resTrans_R_8x8ts[16][16];
extern int resTrans_B_8x8ts[16][16];
extern int resTrans_R[16][16];
extern int resTrans_B[16][16];
extern int mprRGB[3][16][16];
extern int mprRGB_8x8ts[3][16][16];
extern int j;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            int temp_r = mprRGB_8x8ts[0][i][j] + 0;
            int temp_g = mprRGB_8x8ts[1][i][j] + 0;
            int temp_b = mprRGB_8x8ts[2][i][j] + 0;
            mprRGB[0][i][j] = temp_r;
            mprRGB[1][i][j] = temp_g;
            mprRGB[2][i][j] = temp_b;

            int temp_R = resTrans_R_8x8ts[i][j] * 1;
            int temp_B = resTrans_B_8x8ts[i][j] * 1;
            resTrans_R[i][j] = temp_R;
            resTrans_B[i][j] = temp_B;
        }
    }
}
