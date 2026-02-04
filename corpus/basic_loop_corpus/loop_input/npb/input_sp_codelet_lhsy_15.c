#include <stdio.h>

int grid_points[3];
double dy1;
double dy3;
double dy5;
double dymax;
double c1c5;
double c3c4;
double dtty1;
double dtty2;
double c2dtty1;
double con43;
double vs[65][65][65];
double rho_i[65][65][65];
double lhs[15][65][65][65];
double cv[64];
double rhoq[64];
double ru1;
int i;
int j;
int k;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
    
    dy1 = 1.0;
    dy3 = 3.0;
    dy5 = 5.0;
    dymax = 10.0;
    c1c5 = 0.1;
    c3c4 = 0.75;
    dtty1 = 0.2;
    dtty2 = 0.4;
    c2dtty1 = 0.5;
    con43 = 1.333;

    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                vs[ii][jj][kk] = (ii + jj + kk) * 0.01;
                rho_i[ii][jj][kk] = (ii * jj * kk + 1) * 0.001;
                if (ii < 15) {
                    lhs[ii][ii][jj][kk] = 0.0;
                }
            }
        }
    }

    for (int jj = 0; jj < 64; jj++) {
        cv[jj] = jj * 0.1;
        rhoq[jj] = jj * 0.2;
    }

    ru1 = 0.0;
    i = 0;
    j = 0;
    k = 0;
}