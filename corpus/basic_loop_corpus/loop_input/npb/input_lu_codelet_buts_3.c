#include <stdio.h>

int k = 3;
double omega = 1.25;

double v[64][65][65][5];
double tv[64][64][5];
double d[64][64][5][5];
double udx[64][64][5][5];
double udy[64][64][5][5];

int ist = 1;
int iend = 62;
int jst = 1;
int jend = 62;

int i;
int j;
int m;
double tmp;
double tmp1;
double tmat[5][5];

void init_vars() {
    for (int i0 = 0; i0 < 64; i0++) {
        for (int j0 = 0; j0 < 65; j0++) {
            for (int k0 = 0; k0 < 65; k0++) {
                for (int m0 = 0; m0 < 5; m0++) {
                    v[i0][j0][k0][m0] = (i0 + j0 + k0 + m0) * 0.01;
                }
            }
        }
    }

    for (int i0 = 0; i0 < 64; i0++) {
        for (int j0 = 0; j0 < 64; j0++) {
            for (int m0 = 0; m0 < 5; m0++) {
                tv[i0][j0][m0] = 0.0;
                for (int n = 0; n < 5; n++) {
                    d[i0][j0][m0][n] = (m0 == n) ? 1.0 : 0.1;
                    udx[i0][j0][m0][n] = (m0 + n) * 0.01;
                    udy[i0][j0][m0][n] = (m0 + n) * 0.02;
                }
            }
        }
    }

    tmp = 0.0;
    tmp1 = 1.0;

    for (int i0 = 0; i0 < 5; i0++) {
        for (int j0 = 0; j0 < 5; j0++) {
            tmat[i0][j0] = 0.0;
        }
    }
}