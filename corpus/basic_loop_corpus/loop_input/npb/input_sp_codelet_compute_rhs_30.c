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
    // Set grid dimensions to valid values within array bounds
    grid_points[0] = 5;
    grid_points[1] = 65;  // matches second dimension of u and rhs
    grid_points[2] = 65;  // matches third dimension

    // Set dssp to a small non-zero value
    dssp = 0.1;

    // Choose i such that i-1 >= 0 and i+2 < 65 (first spatial dimension bound)
    i = 32;

    // Initialize u and rhs arrays to avoid uninitialized memory usage
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    u[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + 1) * 0.1 + (double)(i_idx + j_idx + k_idx);
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + 1) * 0.01;
                }
            }
        }
    }

    // Initialize loop index variables (though they are typically overwritten in loop)
    j = 0;
    k = 0;
    m = 0;
}