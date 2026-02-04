#include <stdio.h>

int grid_points[3];
double dz1;
double dz4;
double dz5;
double dzmax;
double c1c5;
double c3c4;
double dttz1;
double dttz2;
double c2dttz1;
double con43;
double ws[65][65][65];
double rho_i[65][65][65];
double lhs[15][65][65][65];
double cv[64];
double rhos[64];
double ru1;
int i;
int j;
int k;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    dz1 = 1.0;
    dz4 = 2.0;
    dz5 = 3.0;
    dzmax = 4.0;
    c1c5 = 0.25;
    c3c4 = 0.75;
    dttz1 = 0.1;
    dttz2 = 0.2;
    c2dttz1 = 0.3;
    con43 = 1.333333;

    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                ws[i_idx][j_idx][k_idx] = (i_idx + j_idx + k_idx) * 0.01;
                rho_i[i_idx][j_idx][k_idx] = (i_idx * j_idx * k_idx + 1) * 0.001;
                for (int l_idx = 0; l_idx < 15; l_idx++) {
                    lhs[l_idx][i_idx][j_idx][k_idx] = 0.0;
                }
            }
        }
    }

    for (int k_idx = 0; k_idx < 64; k_idx++) {
        cv[k_idx] = 0.0;
        rhos[k_idx] = 0.0;
    }

    ru1 = 0.0;
    i = 0;
    j = 0;
    k = 0;
}