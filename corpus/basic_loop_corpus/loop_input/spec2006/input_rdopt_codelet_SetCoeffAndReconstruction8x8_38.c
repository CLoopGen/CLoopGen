#include <stdio.h>
#include <inttypes.h>

int resTrans_R_8x8ts[16][16];
int resTrans_B_8x8ts[16][16];
int resTrans_R[16][16];
int resTrans_B[16][16];
int mprRGB[3][16][16];
int mprRGB_8x8ts[3][16][16];
int j;
int i;

void init_vars() {
    for (int jj = 0; jj < 16; ++jj) {
        for (int ii = 0; ii < 16; ++ii) {
            mprRGB_8x8ts[0][ii][jj] = (ii * 16 + jj) % 1000;
            mprRGB_8x8ts[1][ii][jj] = (ii * 16 + jj + 500) % 1000;
            mprRGB_8x8ts[2][ii][jj] = (ii * 16 + jj + 750) % 1000;
            resTrans_R_8x8ts[ii][jj] = ii * jj;
            resTrans_B_8x8ts[ii][jj] = ii + jj;
        }
    }

    for (int c = 0; c < 3; ++c) {
        for (int ii = 0; ii < 16; ++ii) {
            for (int jj = 0; jj < 16; ++jj) {
                mprRGB[c][ii][jj] = 0;
            }
        }
    }

    for (int ii = 0; ii < 16; ++ii) {
        for (int jj = 0; jj < 16; ++jj) {
            resTrans_R[ii][jj] = 0;
            resTrans_B[ii][jj] = 0;
        }
    }

    j = 0;
    i = 0;
}