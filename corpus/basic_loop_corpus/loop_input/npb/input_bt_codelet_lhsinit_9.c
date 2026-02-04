#include <stdio.h>

int grid_points[3];
double lhs[65][65][65][3][5][5];
int i;
int j;
int k;
int m;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int n_idx = 0; n_idx < 3; n_idx++) {
                    for (int p_idx = 0; p_idx < 5; p_idx++) {
                        for (int q_idx = 0; q_idx < 5; q_idx++) {
                            lhs[i_idx][j_idx][k_idx][n_idx][p_idx][q_idx] = 0.0;
                        }
                    }
                }
            }
        }
    }
}