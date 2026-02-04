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
    for (j = 0; j < 16; j++)
        for (i = 0; i < 16; i++) {
            // Introduce WAW dependency by reassigning mprRGB[0] after a computation that depends on prior value
            mprRGB[0][i][j] = mprRGB_8x8ts[0][i][j] + 1;
            mprRGB[0][i][j] = mprRGB[0][i][j] * 2;  // WAW: write-after-write on same element
            mprRGB[1][i][j] = mprRGB_8x8ts[1][i][j];
            mprRGB[2][i][j] = mprRGB_8x8ts[2][i][j];
            resTrans_R[i][j] = resTrans_R_8x8ts[i][j];
            resTrans_B[i][j] = resTrans_B_8x8ts[i][j];
        }
}
