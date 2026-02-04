#include <stdio.h>

int grid_points[3];
double comz1;
double comz4;
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
    comz4 = 2.0;
    comz6 = 3.0;

    for (int i_idx = 0; i_idx < 15; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int l_idx = 0; l_idx < 65; l_idx++) {
                    lhs[i_idx][j_idx][k_idx][l_idx] = (double)(i_idx + j_idx + k_idx + l_idx);
                }
            }
        }
    }
}