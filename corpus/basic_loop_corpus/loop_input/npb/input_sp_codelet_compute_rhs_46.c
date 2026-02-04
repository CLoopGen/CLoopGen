#include <stdio.h>

int grid_points[3];
double dt;
double rhs[5][65][65][65];
int i;
int j;
int k;
int m;

void init_vars() {
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;
    dt = 0.001;

    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + i_idx + j_idx + k_idx);
                }
            }
        }
    }
}