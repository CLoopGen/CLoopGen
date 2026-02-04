#include <stdio.h>

#define GRID_POINTS_0 64
#define GRID_POINTS_1 64
#define GRID_POINTS_2 64

int grid_points[3];
double tx1;
double tx2;
double dx1;
double dx2;
double dx3;
double dx4;
double dx5;
double dt;
double c3c4;
double c1345;
double c1;
double c2;
double con43;
double u[65][65][65][5];
double lhs[65][65][65][3][5][5];
double fjac[65][65][64][5][5];
double njac[65][65][64][5][5];
double tmp1;
double tmp2;
double tmp3;
int i;
int j;
int k;

void init_vars() {
    grid_points[0] = GRID_POINTS_0;
    grid_points[1] = GRID_POINTS_1;
    grid_points[2] = GRID_POINTS_2;

    tx1 = 1.0;
    tx2 = 1.0;
    dx1 = 0.1;
    dx2 = 0.1;
    dx3 = 0.1;
    dx4 = 0.1;
    dx5 = 0.1;
    dt = 0.01;
    c3c4 = 1.5;
    c1345 = 0.8;
    c1 = 1.0;
    c2 = 1.4;
    con43 = 1.333333;

    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int m = 0; m < 5; m++) {
                    if (ii < grid_points[0] && jj < grid_points[1] && kk < grid_points[2]) {
                        u[ii][jj][kk][m] = 1.0 + (ii + jj + kk + m) * 0.01;
                    } else {
                        u[ii][jj][kk][m] = 0.0;
                    }
                    for (int n = 0; n < 5; n++) {
                        if (kk < 64) {
                            fjac[ii][jj][kk][m][n] = 0.0;
                            njac[ii][jj][kk][m][n] = 0.0;
                        }
                        for (int p = 0; p < 3; p++) {
                            lhs[ii][jj][kk][p][m][n] = 0.0;
                        }
                    }
                }
            }
        }
    }

    tmp1 = 0.0;
    tmp2 = 0.0;
    tmp3 = 0.0;
    i = 0;
    j = 0;
    k = 0;
}