#include <stdio.h>
#include <inttypes.h>

int resTrans_R_8x8[16][16];
int resTrans_B_8x8[16][16];
int mprRGB_8x8[3][16][16];
int resTrans_R[16][16];
int resTrans_B[16][16];
int mprRGB[3][16][16];
int j;
int i;

void init_vars() {
    for (int jj = 0; jj < 16; ++jj) {
        for (int ii = 0; ii < 16; ++ii) {
            mprRGB_8x8[0][ii][jj] = (ii * 16 + jj) % 1000;
            mprRGB_8x8[1][ii][jj] = (ii * 16 + jj + 500) % 1000;
            mprRGB_8x8[2][ii][jj] = (ii * 16 + jj + 750) % 1000;
            resTrans_R_8x8[ii][jj] = ii * jj + 1;
            resTrans_B_8x8[ii][jj] = ii * jj + 2;
        }
    }
}