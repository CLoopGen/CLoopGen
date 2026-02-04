#include <stdio.h>

int grid_points[3];
double tx2;
double xxcon2;
double xxcon3;
double xxcon4;
double xxcon5;
double dx1tx1;
double dx2tx1;
double dx3tx1;
double dx4tx1;
double dx5tx1;
double c1;
double c2;
double con43;
double u[5][65][65][65];
double us[65][65][65];
double vs[65][65][65];
double ws[65][65][65];
double qs[65][65][65];
double rho_i[65][65][65];
double square[65][65][65];
double rhs[5][65][65][65];
int i;
int j;
int k;
double uijk;
double up1;
double um1;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    tx2 = 1.0;
    xxcon2 = 1.0;
    xxcon3 = 1.0;
    xxcon4 = 1.0;
    xxcon5 = 1.0;
    dx1tx1 = 1.0;
    dx2tx1 = 1.0;
    dx3tx1 = 1.0;
    dx4tx1 = 1.0;
    dx5tx1 = 1.0;
    c1 = 1.0;
    c2 = 1.0;
    con43 = 1.0;

    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                us[ii][jj][kk] = 1.0 + ii * 0.01 + jj * 0.02 + kk * 0.03;
                vs[ii][jj][kk] = 1.0 + ii * 0.02 + jj * 0.03 + kk * 0.04;
                ws[ii][jj][kk] = 1.0 + ii * 0.03 + jj * 0.04 + kk * 0.05;
                qs[ii][jj][kk] = 1.0 + ii * 0.04 + jj * 0.05 + kk * 0.06;
                rho_i[ii][jj][kk] = 1.0 + ii * 0.05 + jj * 0.06 + kk * 0.07;
                square[ii][jj][kk] = 1.0 + ii * 0.06 + jj * 0.07 + kk * 0.08;
                for (int m = 0; m < 5; m++) {
                    u[m][ii][jj][kk] = 1.0 + m * 0.1 + ii * 0.01 + jj * 0.02 + kk * 0.03;
                    rhs[m][ii][jj][kk] = 0.0;
                }
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    uijk = 0.0;
    up1 = 0.0;
    um1 = 0.0;
}