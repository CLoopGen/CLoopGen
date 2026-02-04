#include <stdio.h>

int grid_points[3];
double rhs[5][65][65][65];
double lhs[15][65][65][65];
int i;
int j;
int k;
int n = 2;
int k1;
int k2;
int m;
double fac1;

void init_vars() {
    // Set grid dimensions to ensure valid loop bounds and target memory usage
    // We aim for ~64MB of data in the largest arrays (lhs and rhs)
    // lhs: 15 * 65^4 * sizeof(double) ≈ 15 * 17.8 MB ≈ 267 MB
    // rhs: 5 * 65^4 * sizeof(double) ≈ 89 MB
    // Total ~356 MB, which is acceptable for modern systems and will run loop long enough

    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;

    // Initialize lhs with non-zero values to avoid division by zero
    for (int n_idx = 0; n_idx < 15; n_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    lhs[n_idx][i_idx][j_idx][k_idx] = (n_idx + 1) * 0.1 + (i_idx % 7) * 0.01 + (j_idx % 5) * 0.001 + (k_idx % 3) * 0.0001 + 1.0;
                }
            }
        }
    }

    // Initialize rhs
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    rhs[m_idx][i_idx][j_idx][k_idx] = (m_idx + 1) * 0.5 + (i_idx % 3) * 0.01 + (j_idx % 4) * 0.005 + (k_idx % 2) * 0.0001;
                }
            }
        }
    }

    // Ensure n is within valid range [0,12] so that n+4 < 15
    n = 2;

    // Initialize loop indices to safe values
    i = 0;
    j = 0;
    k = 0;
    k1 = 0;
    k2 = 0;
    m = 0;
    fac1 = 1.0;
}