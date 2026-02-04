#include <stdio.h>

int grid_points[3];
double forcing[5][65][65][65];
int m;
int i;
int j;
int k;

void init_vars() {
    // Set grid dimensions to ensure memory access bounds are valid
    // The loop runs from 1 to grid_points[x] - 2 for each dimension
    // So we need grid_points[x] <= array size in that dimension
    // Array sizes: forcing is [5][65][65][65], so first index up to 4, others up to 64
    grid_points[0] = 65;  // maps to second dimension (i), max index 64
    grid_points[1] = 65;  // maps to third dimension (j), max index 64
    grid_points[2] = 65;  // maps to fourth dimension (k), max index 64

    // Initialize the forcing array with non-zero values to make transformation observable
    for (m = 0; m < 5; m++) {
        for (i = 0; i < 65; i++) {
            for (j = 0; j < 65; j++) {
                for (k = 0; k < 65; k++) {
                    forcing[m][i][j][k] = (double)(m + 1) * (i + 1) * (j + 1) * (k + 1);
                }
            }
        }
    }

    // Reset loop indices to safe initial values
    m = 0;
    i = 0;
    j = 0;
    k = 0;
}