#include <stdio.h>

int ki1 = 1;
int ki2 = 64;
double u[64][65][65][5];
int j;
int k;
int ibeg = 0;
int jbeg = 1;
int jfin = 64;
int jglob;
double phi1[66][66];

void init_vars() {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 65; j++) {
            for (int k = 0; k < 65; k++) {
                u[i][j][k][0] = 1.0;
                u[i][j][k][1] = 0.1 * (i + 1);
                u[i][j][k][2] = 0.2 * (j + 1);
                u[i][j][k][3] = 0.3 * (k + 1);
                u[i][j][k][4] = 0.4 * (i + j + k + 1);
            }
        }
    }

    for (int j = 0; j < 66; j++) {
        for (int k = 0; k < 66; k++) {
            phi1[j][k] = 0.0;
        }
    }

    ki1 = 1;
    ki2 = 64;
    ibeg = 0;
    jbeg = 1;
    jfin = 64;
}