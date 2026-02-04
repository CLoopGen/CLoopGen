#include <stdio.h>

int grid_points[3] = {64, 64, 64};

double rhs[5][65][65][65];
double lhs[15][65][65][65];

int i = 0;
int j = 0;
int k = 1;
int n = 0;
int k1 = 2;
int m = 0;
double fac1 = 0.0;
double fac2 = 0.0;

void init_vars() {
    int i, j, k, m, n_val;
    
    for (n_val = 0; n_val < 15; n_val++) {
        for (i = 0; i < 65; i++) {
            for (j = 0; j < 65; j++) {
                for (k = 0; k < 65; k++) {
                    lhs[n_val][i][j][k] = (double)(n_val + 1) / (i + j + k + 1);
                }
            }
        }
    }

    for (m = 0; m < 5; m++) {
        for (i = 0; i < 65; i++) {
            for (j = 0; j < 65; j++) {
                for (k = 0; k < 65; k++) {
                    rhs[m][i][j][k] = (double)(m + 1) / (i + j + k + 1);
                }
            }
        }
    }

    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    i = 0;
    j = 0;
    k = 1;
    k1 = 2;
    n = 0;
    fac1 = 0.0;
    fac2 = 0.0;
}