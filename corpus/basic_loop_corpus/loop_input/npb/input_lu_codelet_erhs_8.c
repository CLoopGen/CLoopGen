#include <stdio.h>

int nz = 64;
int ist = 0;
int iend = 63;
double rsd[64][65][65][5];
double flux[64][65][65][5];
int i;
int j;
int k;
int L1 = 0;
int L2 = 64;
double q;
double u31;

void init_vars() {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 65; j++) {
            for (int k = 0; k < 65; k++) {
                for (int m = 0; m < 5; m++) {
                    rsd[i][j][k][m] = (double)(i + j + k + m + 1) * 0.01;
                    flux[i][j][k][m] = 0.0;
                }
            }
        }
    }
    nz = 64;
    ist = 0;
    iend = 63;
    L1 = 0;
    L2 = 64;
}