#include <stdio.h>

int grid_points[3];
double lhs[15][65][65][65];
int i;
int j;
int k;
int n;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    for (int n_idx = 0; n_idx < 15; n_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    lhs[n_idx][i_idx][j_idx][k_idx] = 0.0;
                }
            }
        }
    }
}