#include <stdio.h>

int k = 1;
double omega = 0.5;
double v[64][65][65][5];
double ldy[64][64][5][5];
double ldx[64][64][5][5];
double d[64][64][5][5];
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
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 65; j++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m = 0; m < 5; m++) {
                    v[i][j][k_idx][m] = (i + j + k_idx + m) * 0.01;
                }
            }
        }
    }

    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            for (int m = 0; m < 5; m++) {
                for (int n = 0; n < 5; n++) {
                    ldy[i][j][m][n] = (m + n) * 0.1 + 1.0;
                    ldx[i][j][m][n] = (m + n) * 0.1 + 1.1;
                    d[i][j][m][n] = (m == n) ? 2.0 : 0.1;
                }
            }
        }
    }

    for (int m = 0; m < 5; m++) {
        for (int n = 0; n < 5; n++) {
            tmat[m][n] = 0.0;
        }
    }

    tmp = 0.0;
    tmp1 = 1.0;
}