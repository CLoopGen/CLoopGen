#include <stdio.h>

int grid_points[3];
double comz1;
double comz4;
double comz5;
double comz6;
double lhs[15][65][65][65];
int i;
int j;
int k;

void init_vars() {
    // Set grid dimensions to ensure significant computation but within bounds
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;

    // Initialize scalar coefficients
    comz1 = 1.5;
    comz4 = 2.0;
    comz5 = 1.8;
    comz6 = 2.2;

    // Initialize index variables used in loop
    i = 1; // Ensures i+1 = 2 is within [0,14] for lhs dimension

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

    // Initialize loop indices (though they are overwritten in loop)
    j = 0;
    k = 0;
}