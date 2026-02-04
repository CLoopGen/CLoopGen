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
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;

    // Set i to a value that allows i+2 < 65, and satisfies loop bounds (j from 1 to grid_points[1]-2, etc.)
    i = 3; // ensures i-1=2 and i+2=5 are valid indices

    // Initialize dssp to a reasonable value
    dssp = 0.25;

    // Initialize u and rhs arrays to avoid undefined behavior
    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    u[i_idx][j_idx][k_idx][m_idx] = (i_idx + j_idx + k_idx) * 0.1 + m_idx;
                    rhs[i_idx][j_idx][k_idx][m_idx] = (i_idx * j_idx * k_idx % 100) * 0.01 + m_idx;
                }
            }
        }
    }

    // Initialize scalar loop indices (though they are typically set before calling loop)
    j = 0;
    k = 0;
    m = 0;
}