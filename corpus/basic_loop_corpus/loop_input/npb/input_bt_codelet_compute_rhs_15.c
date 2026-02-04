#include <stdio.h>

#define GRID_SIZE 64

int grid_points[3];
double us[65][65][65];
double vs[65][65][65];
double ws[65][65][65];
double qs[65][65][65];
double rho_i[65][65][65];
double square[65][65][65];
double u[65][65][65][5];
int i;
int j;
int k;
double rho_inv;

void init_vars() {
    grid_points[0] = GRID_SIZE;
    grid_points[1] = GRID_SIZE;
    grid_points[2] = GRID_SIZE;

    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m = 0; m < 5; m++) {
                    u[i_idx][j_idx][k_idx][m] = (m == 0) ? 1.1 : (i_idx + j_idx + k_idx + m);
                }
                us[i_idx][j_idx][k_idx] = 0.0;
                vs[i_idx][j_idx][k_idx] = 0.0;
                ws[i_idx][j_idx][k_idx] = 0.0;
                qs[i_idx][j_idx][k_idx] = 0.0;
                rho_i[i_idx][j_idx][k_idx] = 0.0;
                square[i_idx][j_idx][k_idx] = 0.0;
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    rho_inv = 0.0;
}