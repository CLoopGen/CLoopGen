#include <stdio.h>

#include <inttypes.h>

extern int resTrans_R_8x8[16][16];
extern int resTrans_B_8x8[16][16];
extern int mprRGB_8x8[3][16][16];
extern int resTrans_R[16][16];
extern int resTrans_B[16][16];
extern int mprRGB[3][16][16];
extern int j;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            int temp_r = mprRGB_8x8[0][i][j] * 2;
            int temp_g = mprRGB_8x8[1][i][j] * 2;
            int temp_b = mprRGB_8x8[2][i][j] * 2;
            mprRGB[0][i][j] = temp_r;
            mprRGB[1][i][j] = temp_g;
            mprRGB[2][i][j] = temp_b;
            resTrans_R[i][j] = resTrans_R_8x8[i][j] * 3;
            resTrans_B[i][j] = resTrans_B_8x8[i][j] * 3;
        }
        for (i = 8; i < 16; i++) {
            mprRGB[0][i][j] = mprRGB_8x8[0][i][j];
            mprRGB[1][i][j] = mprRGB_8x8[1][i][j];
            mprRGB[2][i][j] = mprRGB_8x8[2][i][j];
            resTrans_R[i][j] = resTrans_R_8x8[i][j];
            resTrans_B[i][j] = resTrans_B_8x8[i][j];
        }
    }
    for (j = 8; j < 16; j++)
        for (i = 0; i < 16; i++) {
            mprRGB[0][i][j] = mprRGB_8x8[0][i][j] - 5;
            mprRGB[1][i][j] = mprRGB_8x8[1][i][j] - 5;
            mprRGB[2][i][j] = mprRGB_8x8[2][i][j] - 5;
            resTrans_R[i][j] = resTrans_R_8x8[i][j] + 10;
            resTrans_B[i][j] = resTrans_B_8x8[i][j] + 10;
        }
}
