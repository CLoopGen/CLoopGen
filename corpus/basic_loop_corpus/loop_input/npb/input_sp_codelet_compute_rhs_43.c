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
    // Set grid dimensions to fit within array bounds
    // The arrays are declared as [5][65][65][65], so indices: m in [0,4], i,j,k in [0,64]
    grid_points[0] = 65;  // matches second dimension
    grid_points[1] = 65;  // matches third dimension
    grid_points[2] = 65;  // matches fourth dimension

    // Set dssp to a reasonable value
    dssp = 0.1;

    // Initialize u and rhs arrays to prevent undefined behavior
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    u[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + i_idx + j_idx + k_idx) / 100.0;
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx * i_idx * j_idx * k_idx) / 10000.0;
                }
            }
        }
    }

    // Initialize loop indices to safe values
    i = 0;
    j = 0;
    k = 0;
    m = 0;
}