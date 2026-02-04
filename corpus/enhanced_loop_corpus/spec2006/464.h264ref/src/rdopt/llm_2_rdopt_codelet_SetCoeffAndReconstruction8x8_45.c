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
    // Variant 1: Memory Access Pattern Modification - Interchange loops for row-major to column-major access order
    for (i = 0; i < 16; i++)
        for (j = 0; j < 16; j++) {
            mprRGB[0][i][j] = mprRGB_8x8[0][i][j];
            mprRGB[1][i][j] = mprRGB_8x8[1][i][j];
            mprRGB[2][i][j] = mprRGB_8x8[2][i][j];
            resTrans_R[i][j] = resTrans_R_8x8[i][j];
            resTrans_B[i][j] = resTrans_B_8x8[i][j];
        }
}
