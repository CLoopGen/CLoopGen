#include <stdio.h>

int grid_points[3];
double rhs[5][65][65][65];
double lhs[15][65][65][65];
int i;
int j;
int k;
int n = 0;
int i1;
int i2;
int m;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 65;
    grid_points[2] = 65;

    for (int idx = 0; idx < 5; idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    rhs[idx][i_idx][j_idx][k_idx] = (double)(idx + 1) * 0.1;
                }
            }
        }
    }

    for (int idx = 0; idx < 15; idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    lhs[idx][i_idx][j_idx][k_idx] = (double)(idx + 1) * 0.05;
                }
            }
        }
    }
}