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
    dssp = 0.1;
    i = 2;

    for (int idx_i = 0; idx_i < 65; idx_i++) {
        for (int idx_j = 0; idx_j < 65; idx_j++) {
            for (int idx_k = 0; idx_k < 65; idx_k++) {
                for (int idx_m = 0; idx_m < 5; idx_m++) {
                    u[idx_i][idx_j][idx_k][idx_m] = (double)(idx_i + idx_j + idx_k + idx_m);
                    rhs[idx_i][idx_j][idx_k][idx_m] = (double)(idx_i * idx_j * idx_k * idx_m + 1);
                }
            }
        }
    }
}