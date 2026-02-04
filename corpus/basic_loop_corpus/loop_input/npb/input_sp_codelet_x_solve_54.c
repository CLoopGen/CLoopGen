#include <stdio.h>

int grid_points[3];
double rhs[5][65][65][65];
double lhs[15][65][65][65];
int i;
int j;
int k;
int n;
int i1;
int m;

void init_vars() {
    // Initialize grid_points to ensure valid loop bounds
    grid_points[0] = 5;
    grid_points[1] = 64;  // so that j from 1 to grid_points[1]-2 is 1 to 62
    grid_points[2] = 64;  // so that k from 1 to grid_points[2]-2 is 1 to 62

    // Initialize scalar indices used in the loop
    i = 1;
    i1 = 0;
    n = 0;  // ensures n+3 = 3, which is within [0,14] for lhs

    // Initialize arrays to some values to avoid undefined behavior
    // and ensure meaningful memory usage (~tens of MBs)
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
                    lhs[l][i_idx][j_idx][k_idx] = (double)(l + i_idx + j_idx + k_idx) * 0.05;
                }
            }
        }
    }
}