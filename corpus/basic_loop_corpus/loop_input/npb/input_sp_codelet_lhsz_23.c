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
    // Set grid dimensions to ensure sufficient workload
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;

    // Initialize scalar values to non-zero for meaningful computation
    comz1 = 1.0;
    comz4 = 0.5;
    comz5 = 0.7;
    comz6 = 0.3;

    // Initialize k to a safe value within bounds for k+1 access
    k = 1;

    // Initialize lhs array to avoid undefined behavior during updates
    for (int n = 0; n < 15; n++) {
        for (int ii = 0; ii < 65; ii++) {
            for (int jj = 0; jj < 65; jj++) {
                for (int kk = 0; kk < 65; kk++) {
                    lhs[n][ii][jj][kk] = (double)(n + 1);
                }
            }
        }
    }
}