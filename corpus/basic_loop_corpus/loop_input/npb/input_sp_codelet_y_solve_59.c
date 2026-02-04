#include <stdio.h>

int grid_points[3];
double rhs[5][65][65][65];
double lhs[15][65][65][65];
int i;
int j;
int k;
int n;
int j1;
int m;
double fac1;
double fac2;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    n = 0;
    j = 1;
    j1 = 2;

    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                lhs[0][ii][jj][kk] = 1.0;
                lhs[1][ii][jj][kk] = 1.0;
                lhs[2][ii][jj][kk] = 2.0;
                lhs[3][ii][jj][kk] = 1.0;
                lhs[4][ii][jj][kk] = 1.0;
                lhs[5][ii][jj][kk] = 1.0;
                lhs[6][ii][jj][kk] = 1.0;
                lhs[7][ii][jj][kk] = 1.0;
                lhs[8][ii][jj][kk] = 1.0;
                lhs[9][ii][jj][kk] = 1.0;
                lhs[10][ii][jj][kk] = 1.0;
                lhs[11][ii][jj][kk] = 1.0;
                lhs[12][ii][jj][kk] = 1.0;
                lhs[13][ii][jj][kk] = 1.0;
                lhs[14][ii][jj][kk] = 1.0;
            }
        }
    }

    for (int r = 0; r < 5; r++) {
        for (int ii = 0; ii < 65; ii++) {
            for (int jj = 0; jj < 65; jj++) {
                for (int kk = 0; kk < 65; kk++) {
                    rhs[r][ii][jj][kk] = 1.0;
                }
            }
        }
    }

    fac1 = 1.0;
    fac2 = 1.0;
}