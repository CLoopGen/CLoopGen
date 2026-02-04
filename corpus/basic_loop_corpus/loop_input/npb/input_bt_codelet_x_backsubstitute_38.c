#include <stdio.h>

int grid_points[3];
double rhs[65][65][65][5];
double lhs[65][65][65][3][5][5];
int i;
int j;
int k;
int m;
int n;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    for (int i_idx = 0; i_idx < grid_points[0]; i_idx++) {
        for (int j_idx = 0; j_idx < grid_points[1]; j_idx++) {
            for (int k_idx = 0; k_idx < grid_points[2]; k_idx++) {
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    rhs[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx + m_idx) / 10.0;
                    for (int l_idx = 0; l_idx < 3; l_idx++) {
                        for (int n_idx = 0; n_idx < 5; n_idx++) {
                            lhs[i_idx][j_idx][k_idx][l_idx][m_idx][n_idx] = (double)(i_idx % (l_idx + 1) + j_idx % 2 + k_idx % 3 + m_idx + n_idx) / 20.0;
                        }
                    }
                }
            }
        }
    }
}