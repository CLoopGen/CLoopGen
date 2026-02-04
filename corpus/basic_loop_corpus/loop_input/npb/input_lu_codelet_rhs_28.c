#include <stdio.h>

int nx = 64;
int ny = 65;
int nz = 65;
double rsd[64][65][65][5];
double frct[64][65][65][5];
int i;
int j;
int k;
int m;

void init_vars() {
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            for (k = 0; k < nz; k++) {
                for (m = 0; m < 5; m++) {
                    frct[i][j][k][m] = (double)(i + j + k + m);
                }
            }
        }
    }
}