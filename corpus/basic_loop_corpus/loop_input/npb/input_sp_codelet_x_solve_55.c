#include <stdio.h>

int grid_points[3];
double rhs[5][65][65][65];
double lhs[15][65][65][65];
int i = 1;
int j;
int k;
int n;
int i1 = 0;
int m;

void init_vars() {
    // Set grid dimensions to valid values within array bounds
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;

    // Initialize rhs and lhs arrays to non-zero values to simulate realistic data
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + 1) * (i_idx + j_idx + k_idx + 1) / 100.0;
                }
            }
        }
    }

    for (int n_idx = 0; n_idx < 15; n_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    lhs[n_idx][i_idx][j_idx][k_idx] = (double)(n_idx + 1) * (i_idx + j_idx + k_idx + 1) / 50.0;
                }
            }
        }
    }

    // Ensure i and i1 are within valid range [0,64]
    i = 1;
    i1 = 0;
}