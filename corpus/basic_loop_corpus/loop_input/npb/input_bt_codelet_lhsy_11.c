#include <stdio.h>

int grid_points[3];
double c3c4;
double c1345;
double c1;
double c2;
double con43;
double u[65][65][65][5];
double fjac[65][65][64][5][5];
double njac[65][65][64][5][5];
double tmp1;
double tmp2;
double tmp3;
int i;
int j;
int k;

void init_vars() {
    // Set grid dimensions to fit within array bounds and ensure meaningful computation
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    // Initialize constants used in the loop
    c3c4 = 1.0;
    c1345 = 0.5;
    c1 = 1.4;
    c2 = 1.4;
    con43 = 4.0 / 3.0;

    // Initialize u array with non-zero values to avoid division by zero
    for (int i_idx = 0; i_idx < grid_points[0]; i_idx++) {
        for (int j_idx = 0; j_idx < grid_points[1]; j_idx++) {
            for (int k_idx = 0; k_idx < grid_points[2]; k_idx++) {
                u[i_idx][j_idx][k_idx][0] = 1.0 + 0.1 * i_idx;
                u[i_idx][j_idx][k_idx][1] = 0.1 * j_idx;
                u[i_idx][j_idx][k_idx][2] = 0.1 * k_idx;
                u[i_idx][j_idx][k_idx][3] = 0.01 * i_idx;
                u[i_idx][j_idx][k_idx][4] = 1.0;
            }
        }
    }

    // Initialize temporary scalars
    tmp1 = 1.0;
    tmp2 = 1.0;
    tmp3 = 1.0;

    // Zero-initialize fjac and njac arrays (will be overwritten in loop, but safe to pre-clear)
    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 64; k_idx++) {
                for (int m = 0; m < 5; m++) {
                    for (int n = 0; n < 5; n++) {
                        fjac[i_idx][j_idx][k_idx][m][n] = 0.0;
                        njac[i_idx][j_idx][k_idx][m][n] = 0.0;
                    }
                }
            }
        }
    }

    // Initialize loop indices
    i = 0;
    j = 0;
    k = 0;
}