#include <stdio.h>

int grid_points[3];
double forcing[65][65][65][6];
int m;
int i;
int j;
int k;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    for (i = 0; i < 65; i++) {
        for (j = 0; j < 65; j++) {
            for (k = 0; k < 65; k++) {
                for (m = 0; m < 6; m++) {
                    forcing[i][j][k][m] = (double)(i + j + k + m);
                }
            }
        }
    }
}