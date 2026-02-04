#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double two_over_x;
extern double b_jm1;
extern double b_j;
extern double b_jp1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (simulated via index scaling)
    // Assuming b_jm1, b_j, b_jp1 are elements of an array accessed with stride 2
    double *b = (double*)malloc((2 * n + 10) * sizeof(double)); // padded allocation for safety
    int stride = 2;
    b[(1 - 1) * stride] = b_jm1; // b[j-1]
    b[1 * stride] = b_j;         // b[j]
    for (j = 1; j < n; j++) {
        b[(j + 1) * stride] = b[(j - 1) * stride] + j * two_over_x * b[j * stride];
        b[(j - 1) * stride] = b[j * stride];
        b[j * stride] = b[(j + 1) * stride];
    }
    // Update final scalar values to reflect last state
    b_jm1 = b[(n - 1) * stride];
    b_j = b[n * stride];
    free(b);
}
