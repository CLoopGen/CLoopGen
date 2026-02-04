#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int jj;
extern int lb;
extern int ub;
extern int n1;
extern double **in_v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and simplified operations
    int trip_count = (n1 - ub + i + 1) * 2; // Double the effective iterations
    for (jj = 0; jj < trip_count; jj++) {
        int src_idx = (i - lb + jj / 2) % (n1 + 1); // Slower-growing source index with modulo to prevent overflow
        in_v[i][jj % (n1 + 1)] = in_v[i][src_idx]; // Use modulus to stay within bounds
    }
}
