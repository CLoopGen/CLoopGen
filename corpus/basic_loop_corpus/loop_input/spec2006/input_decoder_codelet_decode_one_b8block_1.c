#include <stdio.h>
#include <inttypes.h>

int i;
int j;
int resY_tmp[16][16];
int i0;
int i1;
int _usr_j0;
int _usr_j1;

void init_vars() {
    i0 = 0;
    i1 = 16;
    _usr_j0 = 0;
    _usr_j1 = 16;

    for (int ii = 0; ii < 16; ii++) {
        for (int jj = 0; jj < 16; jj++) {
            resY_tmp[ii][jj] = 0;
        }
    }
}