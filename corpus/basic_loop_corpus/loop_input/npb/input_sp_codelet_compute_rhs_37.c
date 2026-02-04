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
    // Set grid dimensions to ensure valid access within loop bounds
    // j accesses j-2 and j+2, so we need at least 5 points in dimension 1
    // i and k access -1/+1, so need at least 3 points
    grid_points[0] = 65;  // matches second dimension size
    grid_points[1] = 65;  // matches third dimension size
    grid_points[2] = 65;  // matches fourth dimension size

    dssp = 0.1;

    // Initialize u and rhs arrays to avoid undefined behavior
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    u[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + 1) * (i_idx + j_idx + k_idx + 1) / 100.0;
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + 1) * (i_idx * j_idx * k_idx + 1) / 200.0;
                }
            }
        }
    }

    // Initialize loop indices to safe values (will be overwritten in loop)
    i = 0;
    j = 0;
    k = 0;
    m = 0;
}