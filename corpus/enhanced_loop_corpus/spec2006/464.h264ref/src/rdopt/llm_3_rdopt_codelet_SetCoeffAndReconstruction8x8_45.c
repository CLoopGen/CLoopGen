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
    // Variant 2: Memory Access Pattern Modification - Strided access with step size of 2, unroll by 2 iterations
    for (j = 0; j < 16; j += 2)
        for (i = 0; i < 16; i += 2) {
            // First element in 2x2 block
            mprRGB[0][i][j] = mprRGB_8x8[0][i][j];
            mprRGB[1][i][j] = mprRGB_8x8[1][i][j];
            mprRGB[2][i][j] = mprRGB_8x8[2][i][j];
            resTrans_R[i][j] = resTrans_R_8x8[i][j];
            resTrans_B[i][j] = resTrans_B_8x8[i][j];

            // Handle remaining elements in the row if within bounds
            if (i + 1 < 16) {
                mprRGB[0][i+1][j] = mprRGB_8x8[0][i+1][j];
                mprRGB[1][i+1][j] = mprRGB_8x8[1][i+1][j];
                mprRGB[2][i+1][j] = mprRGB_8x8[2][i+1][j];
                resTrans_R[i+1][j] = resTrans_R_8x8[i+1][j];
                resTrans_B[i+1][j] = resTrans_B_8x8[i+1][j];
            }

            // Handle next column if within bounds
            if (j + 1 < 16) {
                mprRGB[0][i][j+1] = mprRGB_8x8[0][i][j+1];
                mprRGB[1][i][j+1] = mprRGB_8x8[1][i][j+1];
                mprRGB[2][i][j+1] = mprRGB_8x8[2][i][j+1];
                resTrans_R[i][j+1] = resTrans_R_8x8[i][j+1];
                resTrans_B[i][j+1] = resTrans_B_8x8[i][j+1];
            }

            // Handle diagonal neighbor if within bounds
            if (i + 1 < 16 && j + 1 < 16) {
                mprRGB[0][i+1][j+1] = mprRGB_8x8[0][i+1][j+1];
                mprRGB[1][i+1][j+1] = mprRGB_8x8[1][i+1][j+1];
                mprRGB[2][i+1][j+1] = mprRGB_8x8[2][i+1][j+1];
                resTrans_R[i+1][j+1] = resTrans_R_8x8[i+1][j+1];
                resTrans_B[i+1][j+1] = resTrans_B_8x8[i+1][j+1];
            }
        }
}
