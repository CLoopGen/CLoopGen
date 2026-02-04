#include <stdio.h>

int grid_points[3] = {64, 64, 64};

double rhs[5][65][65][65];
double forcing[5][65][65][65];

int i;
int j;
int k;
int m;

void init_vars() {
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    forcing[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + i_idx + j_idx + k_idx) * 0.1;
                    rhs[m_idx][i_idx][j_idx][k_idx] = 0.0;
                }
            }
        }
    }
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
}