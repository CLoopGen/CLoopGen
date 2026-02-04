#include <stdio.h>

int grid_points[3];
double bt;
double rhs[5][65][65][65];
int i;
int j;
int k;
double r1;
double r2;
double r3;
double r4;
double r5;
double t1;
double t2;

void init_vars() {
    // Set grid dimensions to ensure the loop runs with valid bounds
    // The original loop uses 1 to grid_points[dim] - 2, so we need at least size 3
    // To achieve ~0.01 seconds runtime, use moderate size: 64x64x64 per the declared array bounds
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;

    // Initialize bt to a reasonable value
    bt = 1.5;

    // Initialize rhs array to non-zero values to simulate realistic data
    for (int ii = 0; ii < 5; ii++) {
        for (int jj = 0; jj < 65; jj++) {
            for (int kk = 0; kk < 65; kk++) {
                for (int ll = 0; ll < 65; ll++) {
                    rhs[ii][jj][kk][ll] = (double)(ii + 1) * (jj % 10 + 1) * (kk % 10 + 1) * (ll % 10 + 1) * 0.01;
                }
            }
        }
    }

    // Initialize scalars used in computation
    r1 = 0.0;
    r2 = 0.0;
    r3 = 0.0;
    r4 = 0.0;
    r5 = 0.0;
    t1 = 0.0;
    t2 = 0.0;
    i = 0;
    j = 0;
    k = 0;
}