#include <stdio.h>

int grid_points[3];
double tz1;
double tz2;
double dz1;
double dz2;
double dz3;
double dz4;
double dz5;
double dt;
double lhs[65][65][65][3][5][5];
double fjac[65][65][64][5][5];
double njac[65][65][64][5][5];
double tmp1;
double tmp2;
int i;
int j;
int k;

void init_vars() {
    // Set grid dimensions to ensure valid loop bounds and target memory size
    // We aim for ~64x64x63 (fjac/njac depth) * 5*5 * sizeof(double) ≈ 100 MB
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    tz1 = 0.1;
    tz2 = 0.2;
    dz1 = 0.01;
    dz2 = 0.02;
    dz3 = 0.03;
    dz4 = 0.04;
    dz5 = 0.05;
    dt = 0.001;

    tmp1 = 0.0;
    tmp2 = 0.0;

    // Initialize lhs array to zero
    for (int i = 0; i < 65; i++) {
        for (int j = 0; j < 65; j++) {
            for (int k = 0; k < 65; k++) {
                for (int d = 0; d < 3; d++) {
                    for (int m = 0; m < 5; m++) {
                        for (int n = 0; n < 5; n++) {
                            lhs[i][j][k][d][m][n] = 0.0;
                        }
                    }
                }
            }
        }
    }

    // Initialize fjac and njac arrays to non-zero values within valid indices
    for (int i = 0; i < 65; i++) {
        for (int j = 0; j < 65; j++) {
            for (int k = 0; k < 64; k++) {
                for (int m = 0; m < 5; m++) {
                    for (int n = 0; n < 5; n++) {
                        fjac[i][j][k][m][n] = (i + j + k + m + n) * 0.001;
                        njac[i][j][k][m][n] = (i + j + k + m + n) * 0.002;
                    }
                }
            }
        }
    }

    // Ensure loop indices are initialized to safe values
    i = 0;
    j = 0;
    k = 0;
}