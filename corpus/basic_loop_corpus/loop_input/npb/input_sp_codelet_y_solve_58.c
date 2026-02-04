#include <stdio.h>

int grid_points[3];
double rhs[5][65][65][65];
double lhs[15][65][65][65];
int i;
int j;
int k;
int n = 2;
int j1;
int j2;
int m;
double fac1;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
    n = 2;

    for (int ii = 0; ii < 15; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int ll = 0; ll < 65; ll++) {
                    lhs[ii][jj][kk][ll] = (double)(ii + jj + kk + ll + 1) * 0.01;
                }
            }
        }
    }

    for (int ii = 0; ii < 5; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int ll = 0; ll < 65; ll++) {
                    rhs[ii][jj][kk][ll] = (double)(ii + jj + kk + ll + 1) * 0.02;
                }
            }
        }
    }
}