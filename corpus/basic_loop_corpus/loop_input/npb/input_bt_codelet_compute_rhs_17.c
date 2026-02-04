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
double us[65][65][65];
double vs[65][65][65];
double ws[65][65][65];
double qs[65][65][65];
double rho_i[65][65][65];
double square[65][65][65];
double u[65][65][65][5];
double rhs[65][65][65][5];
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
    dx1tx1 = 0.1;
    dx2tx1 = 0.1;
    dx3tx1 = 0.1;
    dx4tx1 = 0.1;
    dx5tx1 = 0.1;
    c1 = 1.4;
    c2 = 0.5;
    con43 = 4.0 / 3.0;

    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                us[ii][jj][kk] = (ii + jj + kk) * 0.01;
                vs[ii][jj][kk] = (ii + jj + kk) * 0.02;
                ws[ii][jj][kk] = (ii + jj + kk) * 0.03;
                qs[ii][jj][kk] = (ii + jj + kk) * 0.04;
                rho_i[ii][jj][kk] = (ii + jj + kk) * 0.05;
                square[ii][jj][kk] = (ii + jj + kk) * 0.06;
                for (int m = 0; m < 5; m++) {
                    u[ii][jj][kk][m] = (ii + jj + kk + m) * 0.07;
                    rhs[ii][jj][kk][m] = 0.0;
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