#include <stdio.h>

int grid_points[3];
double comz1;
double comz4;
double comz6;
double lhs[15][65][65][65];
int i;
int j;
int k;

void init_vars() {
    // Set grid dimensions to ensure sufficient data size and safe loop bounds
    grid_points[0] = 65;  // matches first dimension bound in lhs
    grid_points[1] = 65;  // matches second dimension bound in lhs
    grid_points[2] = 65;  // matches third dimension bound in lhs

    // Initialize scalar constants
    comz1 = 1.0;
    comz4 = 2.0;
    comz6 = 3.0;

    // Initialize lhs array to avoid undefined behavior
    for (int ii = 0; ii < 15; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int ll = 0; ll < 65; ll++) {
                    lhs[ii][jj][kk][ll] = (double)(ii + jj + kk + ll) * 0.1;
                }
            }
        }
    }

    // Initialize loop indices to safe values
    i = 0;
    j = 0;
    k = 0;
}