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
double fac1;
double fac2;

void init_vars() {
    // Set grid dimensions to ensure valid loop bounds
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;

    // Set loop indices within valid range
    i = 1;
    i1 = 2;
    n = 0;  // ensures n+4 <= 14 (within lhs bounds)

    // Initialize arrays to avoid NaN or infinity that could cause performance issues
    for (int ii = 0; ii < 5; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int ll = 0; ll < 65; ll++) {
                    rhs[ii][jj][kk][ll] = (double)(ii + 1) * 0.1;
                }
            }
        }
    }

    for (int nn = 0; nn < 15; nn++) {
        for (int ii = 0; ii < 65; ii++) {
            for (int jj = 0; jj < 65; jj++) {
                for (int kk = 0; kk < 65; kk++) {
                    lhs[nn][ii][jj][kk] = (double)(nn + 1) * 0.2;
                }
            }
        }
    }

    // Ensure no division by zero
    fac1 = 1.0;
    fac2 = 1.0;
}