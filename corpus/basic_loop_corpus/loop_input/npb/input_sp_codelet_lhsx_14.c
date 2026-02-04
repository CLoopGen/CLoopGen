#include <stdio.h>

int grid_points[3];
double dttx2;
double speed[65][65][65];
double lhs[15][65][65][65];
int i;
int j;
int k;

void init_vars() {
    // Set grid dimensions to ensure meaningful loop bounds and data size
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    // Initialize dttx2 to a small positive value
    dttx2 = 0.1;

    // Initialize speed array to avoid NaN/undefined behavior
    for (int ii = 0; ii < 65; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                speed[ii][jj][kk] = (ii + jj + kk) * 0.1;
            }
        }
    }

    // Initialize lhs array
    for (int ll = 0; ll < 15; ll++) {
        for (int ii = 0; ii < 65; ii++) {
            for (int jj = 0; jj < 65; jj++) {
                for (int kk = 0; kk < 65; kk++) {
                    lhs[ll][ii][jj][kk] = (ll * 1000 + ii * 100 + jj * 10 + kk) * 0.01;
                }
            }
        }
    }

    // Initialize loop indices
    i = 0;
    j = 0;
    k = 0;
}