#include <stdio.h>

int grid_points[3] = {64, 64, 64};
double dssp = 0.1;
double u[65][65][65][5];
double rhs[65][65][65][5];
int i, j, k, m;

void init_vars() {
    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int mm = 0; mm < 5; mm++) {
                    u[ii][jj][kk][mm] = (double)(ii + jj + kk + mm) * 0.01;
                    rhs[ii][jj][kk][mm] = (double)(ii + jj + kk + mm) * 0.02;
                }
            }
        }
    }
    i = 0; j = 0; k = 1;
}