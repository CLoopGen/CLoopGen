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
    // Set grid dimensions to 64x64x64 to match array bounds and ensure loop safety
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
    
    // Set dssp to a small positive value
    dssp = 0.1;
    
    // Initialize u and rhs arrays to prevent undefined behavior
    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    u[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx) * 0.001 + m_idx;
                    rhs[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx - j_idx + k_idx) * 0.002 - m_idx;
                }
            }
        }
    }
}