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
    for (j = 0; j < 16; j += 2)
        for (i = 0; i < 16; i += 2) {
            mprRGB[0][i][j] = mprRGB_8x8[0][i][j] + 1;
            mprRGB[1][i][j] = mprRGB_8x8[1][i][j] + 2;
            mprRGB[2][i][j] = mprRGB_8x8[2][i][j] + 3;
            resTrans_R[i][j] = resTrans_R_8x8[i][j] - 1;
            resTrans_B[i][j] = resTrans_B_8x8[i][j] - 2;

            if (i+1 < 16 && j+1 < 16) {
                mprRGB[0][i+1][j+1] = mprRGB_8x8[0][i+1][j+1] + 1;
                mprRGB[1][i+1][j+1] = mprRGB_8x8[1][i+1][j+1] + 2;
                mprRGB[2][i+1][j+1] = mprRGB_8x8[2][i+1][j+1] + 3;
                resTrans_R[i+1][j+1] = resTrans_R_8x8[i+1][j+1] - 1;
                resTrans_B[i+1][j+1] = resTrans_B_8x8[i+1][j+1] - 2;
            }
        }
}
