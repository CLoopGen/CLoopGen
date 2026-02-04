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
    for (j = 0; j < 16; j++)
        for (i = 0; i < 16; i++) {
            // Introduce WAW dependency by writing to same location twice
            resTrans_R[i][j] = resTrans_R_8x8[i][j];
            resTrans_R[i][j] += 1; // Write after write: creates WAW within the same iteration

            resTrans_B[i][j] = resTrans_B_8x8[i][j];
            mprRGB[0][i][j] = mprRGB_8x8[0][i][j];
            mprRGB[1][i][j] = mprRGB_8x8[1][i][j];
            mprRGB[2][i][j] = mprRGB_8x8[2][i][j];
        }
}
