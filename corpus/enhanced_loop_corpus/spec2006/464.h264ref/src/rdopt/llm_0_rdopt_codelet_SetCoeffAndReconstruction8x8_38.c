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
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 16; i++) {
            for (int c = 0; c < 3; c++) {
                mprRGB[c][i][j] = mprRGB_8x8ts[c][i][j];
            }
            resTrans_R[i][j] = resTrans_R_8x8ts[i][j];
            resTrans_B[i][j] = resTrans_B_8x8ts[i][j];
        }
    }
}
