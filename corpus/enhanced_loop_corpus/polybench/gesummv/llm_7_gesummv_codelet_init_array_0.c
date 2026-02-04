#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern double x[1300];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate loop-carried dependencies by reordering and introducing local temporaries
// Unroll the inner loop by factor of 2 (where possible) and remove redundant computations
double temp_a, temp_b;
for (i = 0; i < n; i++) {
    // Remove dependency between x[i] and loop index by computing independently
    temp_a = (double)(i % n) / n;
    x[i] = temp_a;
    j = 0;
    // Process two elements per iteration to reduce trip count and break potential RAW hazards
    for (; j < n - 1; j += 2) {
        temp_a = (double)((i * j + 1) % n) / n;
        temp_b = (double)((i * (j+1) + 1) % n) / n;
        A[i][j] = temp_a;
        A[i][j+1] = temp_b;

        temp_a = (double)((i * j + 2) % n) / n;
        temp_b = (double)((i * (j+1) + 2) % n) / n;
        B[i][j] = temp_a;
        B[i][j+1] = temp_b;
    }
    // Handle odd-sized n
    if (j == n - 1) {
        A[i][j] = (double)((i * j + 1) % n) / n;
        B[i][j] = (double)((i * j + 2) % n) / n;
    }
}
// No loop-carried dependencies; all writes are independent
}
