#include <stdio.h>

int grid_points[3];
double dx1;
double dx2;
double dx5;
double dxmax;
double c1c5;
double c3c4;
double dttx1;
double dttx2;
double c2dttx1;
double con43;
double us[65][65][65];
double rho_i[65][65][65];
double lhs[15][65][65][65];
double cv[64];
double rhon[64];
double ru1;
int i;
int j;
int k;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
    
    dx1 = 0.1;
    dx2 = 0.2;
    dx5 = 0.5;
    dxmax = 1.0;
    c1c5 = 1.25;
    c3c4 = 0.75;
    dttx1 = 0.01;
    dttx2 = 0.02;
    c2dttx1 = 0.03;
    con43 = 1.333;

    for (int ii = 0; ii < 65; ++ii) {
        for (int jj = 0; jj < 65; ++jj) {
            for (int kk = 0; kk < 65; ++kk) {
                us[ii][jj][kk] = (ii + jj + kk) * 0.01;
                rho_i[ii][jj][kk] = 1.0 + (ii * jj * kk) * 1e-6;
                for (int ll = 0; ll < 15; ++ll) {
                    lhs[ll][ii][jj][kk] = 0.0;
                }
            }
        }
    }

    for (int ii = 0; ii < 64; ++ii) {
        cv[ii] = ii * 0.1;
        rhon[ii] = 1.0 + ii * 0.05;
    }

    ru1 = 0.0;
    i = 0;
    j = 0;
    k = 0;
}