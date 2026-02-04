#include <stdio.h>

int grid_points[3];
double rhs[65][65][65][5];
double lhs[65][65][65][3][5][5];
int i;
int j;
int k;
int m;
int n;

void init_vars() {
    // Set grid dimensions to fit within array bounds
    // Array sizes are 65 in each dimension, so set grid_points less than that
    grid_points[0] = 64;  // i from 1 to 62
    grid_points[1] = 64;  // j from 0 to 62 (loop goes downward from grid_points[1]-2)
    grid_points[2] = 64;  // k from 1 to 62

    // Initialize rhs with non-zero values to make computation meaningful
    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    rhs[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx + m_idx + 1) * 0.1;
                }
            }
        }
    }

    // Initialize lhs with non-zero values
    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int l_idx = 0; l_idx < 3; l_idx++) {
                    for (int m_idx = 0; m_idx < 5; m_idx++) {
                        for (int n_idx = 0; n_idx < 5; n_idx++) {
                            lhs[i_idx][j_idx][k_idx][l_idx][m_idx][n_idx] = 
                                (double)(i_idx + j_idx + k_idx + l_idx + m_idx + n_idx + 1) * 0.01;
                        }
                    }
                }
            }
        }
    }

    // Initialize loop indices to safe values (will be overwritten in loop, but good practice)
    i = 0;
    j = 0;
    k = 0;
    m = 0;
    n = 0;
}