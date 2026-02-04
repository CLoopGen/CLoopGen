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
    // Set grid dimensions to valid values within array bounds
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    // Initialize k to a value that ensures k-2 and k+1 are in bounds: 2 <= k <= 62
    k = 32;

    // Set dssp to a reasonable physical constant
    dssp = 0.1;

    // Initialize u and rhs arrays to avoid undefined behavior
    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    u[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx) * 0.01;
                    rhs[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx) * 0.02;
                }
            }
        }
    }
}