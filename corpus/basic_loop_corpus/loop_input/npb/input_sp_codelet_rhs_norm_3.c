#include <stdio.h>

int grid_points[3] = {64, 64, 64};

double rhs[5][65][65][65];
double rms[5];

int i;
int j;
int k;
int m;
double add;

void init_vars() {
    for (int m = 0; m < 5; m++) {
        rms[m] = 0.0;
        for (int i = 0; i < 65; i++) {
            for (int j = 0; j < 65; j++) {
                for (int k = 0; k < 65; k++) {
                    rhs[m][i][j][k] = (double)(i + j + k + m);
                }
            }
        }
    }
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
}