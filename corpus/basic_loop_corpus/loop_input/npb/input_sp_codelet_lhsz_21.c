#include <stdio.h>

int grid_points[3];
double comz1;
double comz4;
double comz5;
double comz6;
double lhs[15][65][65][65];
int i;
int j;
int k;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
    comz1 = 1.0;
    comz4 = 0.75;
    comz5 = 0.5;
    comz6 = 1.25;
    k = 1;

    for (int ii = 0; ii < 15; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int ll = 0; ll < 65; ll++) {
                    lhs[ii][jj][kk][ll] = (double)(ii + jj + kk + ll);
                }
            }
        }
    }
}