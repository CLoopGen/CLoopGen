#include <stdio.h>

int ki1 = 1;
int ki2 = 64;
double u[64][65][65][5];
int j;
int k;
int ifin = 63;
int jbeg = 1;
int jfin = 64;
int jglob;
double phi2[66][66];

void init_vars() {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 65; j++) {
            for (int k = 0; k < 65; k++) {
                u[i][j][k][0] = 1.0;
                u[i][j][k][1] = 2.0;
                u[i][j][k][2] = 3.0;
                u[i][j][k][3] = 4.0;
                u[i][j][k][4] = 5.0;
            }
        }
    }

    for (int j = 0; j < 66; j++) {
        for (int k = 0; k < 66; k++) {
            phi2[j][k] = 0.0;
        }
    }

    ki1 = 1;
    ki2 = 64;
    jbeg = 1;
    jfin = 64;
    ifin = 63;
}