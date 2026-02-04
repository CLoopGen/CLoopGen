#include <stdio.h>

int ki1 = 1;
int ki2 = 64;
double u[64][65][65][5];
int i;
int k;
int ibeg = 1;
int ifin = 63;
int jbeg = 0;
int iglob;
double phi1[66][66];

void init_vars() {
    for (int i_idx = 0; i_idx < 64; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                double rho = 1.0 + 0.1 * i_idx;
                double u1 = 0.2 * j_idx;
                double u2 = 0.1 * k_idx;
                double u3 = 0.05 * (i_idx + j_idx);
                double e = 2.5 + 0.1 * k_idx;
                u[i_idx][j_idx][k_idx][0] = rho;
                u[i_idx][j_idx][k_idx][1] = u1;
                u[i_idx][j_idx][k_idx][2] = u2;
                u[i_idx][j_idx][k_idx][3] = u3;
                u[i_idx][j_idx][k_idx][4] = e;
            }
        }
    }

    for (int i_idx = 0; i_idx < 66; i_idx++) {
        for (int k_idx = 0; k_idx < 66; k_idx++) {
            phi1[i_idx][k_idx] = 0.0;
        }
    }

    ki1 = 1;
    ki2 = 64;
    ibeg = 1;
    ifin = 63;
    jbeg = 0;
}