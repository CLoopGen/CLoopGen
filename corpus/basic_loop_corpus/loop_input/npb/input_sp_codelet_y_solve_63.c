#include <stdio.h>

int grid_points[3];
double rhs[5][65][65][65];
double lhs[15][65][65][65];
int i;
int j;
int k;
int n;
int j1;
int j2;
int m;

void init_vars() {
    // Set grid dimensions to ensure valid access within loop bounds
    grid_points[0] = 64;  // i from 1 to grid_points[0]-2 => max 62
    grid_points[1] = 64;  // j from grid_points[1]-3 down to 0 => j=61,60,...,0; j1=j+1, j2=j+2 => max j2=63 < 65
    grid_points[2] = 64;  // k from 1 to grid_points[2]-2 => max 62

    // Initialize n to a valid value such that n+4 < 15 (since lhs has 15 as first dim)
    // Choose n=5 so that n+3=8, n+4=9 are valid indices
    n = 5;

    // Initialize arrays to non-zero values to avoid optimization away
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    rhs[m_idx][i_idx][j_idx][k_idx] = 1.0 + (m_idx * i_idx + j_idx + k_idx) % 17;
                }
            }
        }
    }

    for (int l_idx = 0; l_idx < 15; l_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    lhs[l_idx][i_idx][j_idx][k_idx] = 0.1 + (l_idx * i_idx + j_idx + k_idx) % 13;
                }
            }
        }
    }

    // Initialize loop indices to safe values
    i = 0;
    j = 0;
    k = 0;
    m = 0;
    j1 = 0;
    j2 = 0;
}