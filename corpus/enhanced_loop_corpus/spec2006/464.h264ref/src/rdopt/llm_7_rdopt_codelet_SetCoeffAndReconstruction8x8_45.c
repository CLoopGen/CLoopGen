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
    int temp_r, temp_b;
    for (j = 0; j < 16; j++)
        for (i = 0; i < 16; i++) {
            // Eliminate direct assignments and introduce RAW dependencies via temporary variables
            temp_r = resTrans_R_8x8[i][j];
            temp_b = resTrans_B_8x8[i][j];

            // Use temporaries to create explicit RAW dependencies
            resTrans_R[i][j] = temp_r;
            resTrans_B[i][j] = temp_b;

            // Chain dependent operations on mprRGB using prior computations (artificially introducing loop-carried dependency)
            if (i > 0) {
                mprRGB[0][i][j] = mprRGB_8x8[0][i][j] + mprRGB[0][i-1][j]; // RAW: depends on previous i
            } else {
                mprRGB[0][i][j] = mprRGB_8x8[0][i][j];
            }

            mprRGB[1][i][j] = mprRGB_8x8[1][i][j];
            mprRGB[2][i][j] = mprRGB_8x8[2][i][j];
        }
}
