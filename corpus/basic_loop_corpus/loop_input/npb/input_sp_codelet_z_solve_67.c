#include <stdio.h>

int grid_points[3];
double rhs[5][65][65][65];
double lhs[15][65][65][65];
int i;
int j;
int k;
int n;
int k1;
int k2;
int m;
double fac1;
double fac2;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + 1) * 0.1 + i_idx * 0.001 + j_idx * 0.0001 + k_idx * 0.00001;
                }
            }
        }
    }

    for (int n_idx = 0; n_idx < 15; n_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    lhs[n_idx][i_idx][j_idx][k_idx] = (double)(n_idx + 1) * 0.2 + (i_idx % 7) * 0.01 + (j_idx % 7) * 0.001 + (k_idx % 7) * 0.0001;
                    if (lhs[n_idx][i_idx][j_idx][k_idx] == 0.0) {
                        lhs[n_idx][i_idx][j_idx][k_idx] = 1.0;
                    }
                }
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    n = 0;
    k1 = 0;
    k2 = 0;
    m = 0;
    fac1 = 1.0;
    fac2 = 1.0;
}