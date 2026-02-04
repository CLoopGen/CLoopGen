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
    // Set grid dimensions
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;

    // Set stencil parameter
    dssp = 0.1;

    // Set loop index i to be in valid range: 2 <= i <= 62 to avoid out-of-bounds access
    // since the loop accesses i-2, i-1, i, i+1 -> requires i+1 <= 64 => i <= 63 and i-2 >= 0 => i >= 2
    i = 32;

    // Initialize u and rhs arrays with non-zero values to simulate realistic data
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    u[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + 1) * (i_idx + j_idx + k_idx + 1) * 1e-3;
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + 1) * (i_idx + j_idx + k_idx + 1) * 1e-6;
                }
            }
        }
    }
}