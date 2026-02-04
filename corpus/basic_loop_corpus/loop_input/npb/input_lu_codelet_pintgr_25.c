#include <stdio.h>

int ki1 = 1;
int ki2 = 64;
double u[64][65][65][5];
int i;
int k;
int ibeg = 1;
int ifin = 63;
int jfin = 64;
int iglob;
double phi2[66][66];

void init_vars() {
    for (int i0 = 0; i0 < 64; i0++) {
        for (int i1 = 0; i1 < 65; i1++) {
            for (int i2 = 0; i2 < 65; i2++) {
                for (int i3 = 0; i3 < 5; i3++) {
                    u[i0][i1][i2][i3] = (double)(i0 + i1 + i2 + i3) / (i3 + 1);
                }
            }
        }
    }
    for (int i0 = 0; i0 < 66; i0++) {
        for (int i1 = 0; i1 < 66; i1++) {
            phi2[i0][i1] = 0.0;
        }
    }
    ki1 = 1;
    ki2 = 64;
    ibeg = 1;
    ifin = 63;
    jfin = 64;
}