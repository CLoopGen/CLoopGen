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
    grid_points[1] = 65;  // matches second dimension size
    grid_points[2] = 65;  // matches third and fourth dimension size

    // Set stencil parameters
    dssp = 0.25;

    // Initialize i to a safe value such that i+2 < 65 (since we access u[m][i+2][j][k])
    i = 1;

    // Initialize arrays with non-zero values to simulate realistic data
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    u[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + i_idx + j_idx + k_idx) * 0.1;
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + i_idx + j_idx + k_idx) * 0.2;
                }
            }
        }
    }

    // Reset loop indices to prevent unintended side effects
    j = 0;
    k = 0;
    m = 0;
}