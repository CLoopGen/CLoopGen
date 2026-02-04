#include <stdio.h>

int grid_points[3];
double dssp;
double u[5][65][65][65];
double rhs[5][65][65][65];
int i;
int j;
int k;
int m;

void init_vars() {
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;
    dssp = 0.1;
    i = 2;

    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                rhs[m_idx][i][j_idx][k_idx] = 1.0;
                u[m_idx][i-2][j_idx][k_idx] = 1.0;
                u[m_idx][i-1][j_idx][k_idx] = 2.0;
                u[m_idx][i][j_idx][k_idx] = 3.0;
            }
        }
    }

    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    if (!(i_idx == i && j_idx >= 1 && j_idx <= grid_points[1]-2 && 
                          k_idx >= 1 && k_idx <= grid_points[2]-2)) {
                        u[m_idx][i_idx][j_idx][k_idx] = (m_idx + i_idx + j_idx + k_idx) * 0.1;
                    }
                }
            }
        }
    }
}