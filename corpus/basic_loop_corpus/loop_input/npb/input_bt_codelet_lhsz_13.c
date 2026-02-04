#include <stdio.h>

int grid_points[3];
double c3c4;
double c1345;
double c1;
double c2;
double c3;
double c4;
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
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
    c3c4 = 1.2;
    c1345 = 0.8;
    c1 = 1.0;
    c2 = 1.4;
    c3 = 0.5;
    c4 = 2.4;
    con43 = 1.3333333333333333;

    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m = 0; m < 5; m++) {
                    u[i_idx][j_idx][k_idx][m] = (i_idx + j_idx + k_idx + m + 1) * 0.1;
                }
            }
        }
    }

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

    tmp1 = 0.0;
    tmp2 = 0.0;
    tmp3 = 0.0;
    i = 0;
    j = 0;
    k = 0;
}