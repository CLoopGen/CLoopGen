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
    // Variant 2: Strided memory access with step size of 2, processing elements in a non-sequential pattern
    // First pass: even indices
    for (j = 0; j < 16; j += 2)
        for (i = 0; i < 16; i++) {
            mprRGB[0][i][j] = mprRGB_8x8ts[0][i][j];
            mprRGB[1][i][j] = mprRGB_8x8ts[1][i][j];
            mprRGB[2][i][j] = mprRGB_8x8ts[2][i][j];
            resTrans_R[i][j] = resTrans_R_8x8ts[i][j];
            resTrans_B[i][j] = resTrans_B_8x8ts[i][j];
        }

    // Second pass: odd indices
    for (j = 1; j < 16; j += 2)
        for (i = 0; i < 16; i++) {
            mprRGB[0][i][j] = mprRGB_8x8ts[0][i][j];
            mprRGB[1][i][j] = mprRGB_8x8ts[1][i][j];
            mprRGB[2][i][j] = mprRGB_8x8ts[2][i][j];
            resTrans_R[i][j] = resTrans_R_8x8ts[i][j];
            resTrans_B[i][j] = resTrans_B_8x8ts[i][j];
        }
}
