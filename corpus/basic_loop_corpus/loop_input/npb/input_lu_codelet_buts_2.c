#include <stdio.h>

int k = 0;
double omega = 1.5;
double v[64][65][65][5];
double tv[64][64][5];
double udz[64][64][5][5];
int ist = 0;
int iend = 63;
int jst = 0;
int jend = 63;
int i, j, m;

void init_vars() {
    for (int i0 = 0; i0 < 64; i0++) {
        for (int i1 = 0; i1 < 65; i1++) {
            for (int i2 = 0; i2 < 65; i2++) {
                for (int i3 = 0; i3 < 5; i3++) {
                    v[i0][i1][i2][i3] = (double)(i0 + i1 + i2 + i3) * 0.1;
                }
            }
        }
    }

    for (int i0 = 0; i0 < 64; i0++) {
        for (int i1 = 0; i1 < 64; i1++) {
            for (int i2 = 0; i2 < 5; i2++) {
                tv[i0][i1][i2] = 0.0;
                for (int i3 = 0; i3 < 5; i3++) {
                    udz[i0][i1][i2][i3] = (double)(i0 + i1 + i2 + i3) * 0.2;
                }
            }
        }
    }

    k = 0;
    omega = 1.5;
    ist = 0;
    iend = 63;
    jst = 0;
    jend = 63;
}