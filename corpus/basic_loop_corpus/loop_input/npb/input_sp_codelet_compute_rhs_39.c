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
    // Set grid dimensions to fit within declared array bounds
    grid_points[0] = 64;  // so that i goes from 1 to 62 (<= 64-2)
    grid_points[1] = 64;  // unused in loop, but set for consistency
    grid_points[2] = 64;  // so that k goes from 1 to 62

    // Set j to a valid index such that j-2 >= 0 and j <= 64
    j = 2;  // ensures j-2 = 0, which is valid

    // Set dssp to a reasonable value
    dssp = 0.25;

    // Initialize u and rhs arrays to avoid undefined behavior
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    u[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + i_idx + j_idx + k_idx) * 0.1;
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx * 1000 + i_idx * 100 + j_idx * 10 + k_idx) * 0.01;
                }
            }
        }
    }

    // Initialize loop indices to safe values (though they are controlled by the loop)
    i = 0;
    k = 0;
    m = 0;
}