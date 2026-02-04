#include <stdio.h>

int grid_points[3];
double rhs[5][65][65][65];
double lhs[15][65][65][65];
int i;
int j;
int k;
int n = 0;
int i1;
int i2;
int m;
double fac1;

void init_vars() {
    // Set grid dimensions to ensure sufficient work without out-of-bounds access
    grid_points[0] = 64;  // So that i <= grid_points[0]-3 -> i <= 61, and i2 = i+2 <= 63 < 65
    grid_points[1] = 64;  // j from 1 to 62 inclusive (<=64-2)
    grid_points[2] = 64;  // k from 1 to 62 inclusive

    // Initialize n to a valid index such that n+4 < 15 (since lhs[n+4] is accessed)
    n = 0;  // ensures indices from n to n+4 are in [0..4], which is safe

    // Initialize arrays to non-zero values to avoid division by zero or trivial math
    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int ni = 0; ni < 15; ni++) {
                    lhs[ni][ii][jj][kk] = 1.0 + (ni % 7) * 0.1 * (ii + jj + kk + 1);
                }
                for (int rm = 0; rm < 5; rm++) {
                    rhs[rm][ii][jj][kk] = 1.0 + (rm % 3) * 0.1 * (ii + jj + kk + 1);
                }
            }
        }
    }

    // Ensure no division by zero in loop: lhs[n+2][i][j][k] must not be zero
    for (int ii = 0; ii <= grid_points[0] - 1; ii++) {
        for (int jj = 1; jj <= grid_points[1] - 2; jj++) {
            for (int kk = 1; kk <= grid_points[2] - 2; kk++) {
                if (lhs[n + 2][ii][jj][kk] == 0.0) {
                    lhs[n + 2][ii][jj][kk] = 1.0;
                }
            }
        }
    }
}