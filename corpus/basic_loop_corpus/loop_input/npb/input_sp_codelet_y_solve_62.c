#include <stdio.h>

int grid_points[3];
double rhs[5][65][65][65];
double lhs[15][65][65][65];
int i;
int j;
int k;
int n;
int j1;
int m;

void init_vars() {
    // Set grid dimensions to fit within array bounds
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;

    // Set loop indices to valid values used in the loop
    j = 1;        // j is used as fixed index in rhs[m][i][j][k]
    j1 = 0;       // j1 must be within [0,64], and different from j

    // Initialize rhs and lhs arrays to non-zero values to avoid optimization away
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + i_idx + j_idx + k_idx) * 0.1;
                }
            }
        }
    }

    for (int l = 0; l < 15; l++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    lhs[l][i_idx][j_idx][k_idx] = (double)(l + i_idx + j_idx + k_idx) * 0.01;
                }
            }
        }
    }
}