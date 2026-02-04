#include <stdio.h>

int grid_points[3];
double dssp;
double u[65][65][65][5];
double rhs[65][65][65][5];
int i;
int j;
int k;
int m;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
    dssp = 0.1;

    k = 1;

    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    u[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx + m_idx) / 10.0;
                    rhs[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx + m_idx) / 100.0;
                }
            }
        }
    }
}