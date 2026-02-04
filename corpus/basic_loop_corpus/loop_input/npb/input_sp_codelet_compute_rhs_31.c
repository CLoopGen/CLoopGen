#include <stdio.h>

int grid_points[3];
double dssp;
double u[5][65][65][65];
double rhs[5][65][65][65];
int i;
int j;
int k;
int m;

void init_vars() {
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;
    dssp = 0.1;

    for (int m = 0; m < 5; m++) {
        for (int i = 0; i < 65; i++) {
            for (int j = 0; j < 65; j++) {
                for (int k = 0; k < 65; k++) {
                    u[m][i][j][k] = (double)(m + i + j + k) * 0.001;
                    rhs[m][i][j][k] = (double)(m * i * j * k + 1) * 0.0001;
                }
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    m = 0;
}