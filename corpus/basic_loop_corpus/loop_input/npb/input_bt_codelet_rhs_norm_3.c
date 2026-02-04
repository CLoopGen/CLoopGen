#include <stdio.h>

int grid_points[3];
double rhs[65][65][65][5];
double rms[5];
int i;
int j;
int k;
int m;
double add;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    for (int ii = 0; ii < 65; ++ii) {
        for (int jj = 0; jj < 65; ++jj) {
            for (int kk = 0; kk < 65; ++kk) {
                for (int mm = 0; mm < 5; ++mm) {
                    rhs[ii][jj][kk][mm] = (double)(ii + jj + kk + mm) * 0.1;
                }
            }
        }
    }

    for (int mm = 0; mm < 5; ++mm) {
        rms[mm] = 0.0;
    }

    i = 0;
    j = 0;
    k = 0;
    m = 0;
    add = 0.0;
}