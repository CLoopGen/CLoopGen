#include <stdio.h>

int grid_points[3] = {64, 64, 64};

double rhs[5][65][65][65];
double lhs[15][65][65][65];

int i;
int j;
int k = 32;
int n;
int k1 = 31;
int m;

void init_vars() {
    for (int m0 = 0; m0 < 5; m0++) {
        for (int i0 = 0; i0 < 65; i0++) {
            for (int j0 = 0; j0 < 65; j0++) {
                for (int k0 = 0; k0 < 65; k0++) {
                    rhs[m0][i0][j0][k0] = (double)(m0 + 1) * (i0 + j0 + k0 + 1);
                }
            }
        }
    }

    for (int n0 = 0; n0 < 15; n0++) {
        for (int i0 = 0; i0 < 65; i0++) {
            for (int j0 = 0; j0 < 65; j0++) {
                for (int k0 = 0; k0 < 65; k0++) {
                    lhs[n0][i0][j0][k0] = (double)(n0 + 1) * (i0 + j0 + k0 + 1);
                }
            }
        }
    }

    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
    k = 32;
    k1 = 31;
}