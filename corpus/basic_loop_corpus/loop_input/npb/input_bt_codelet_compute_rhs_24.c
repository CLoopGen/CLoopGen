#include <stdio.h>

int grid_points[3];
double dssp;
double u[65][65][65][5];
double rhs[65][65][65][5];
int i;
int j;
int k;
int m;

void init_vars() {
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;
    dssp = 0.25;
    j = 1;

    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int mm = 0; mm < 5; mm++) {
                    u[ii][jj][kk][mm] = (double)(ii + jj + kk + mm) * 0.1;
                    rhs[ii][jj][kk][mm] = (double)(ii + jj + kk + mm) * 0.2;
                }
            }
        }
    }
}