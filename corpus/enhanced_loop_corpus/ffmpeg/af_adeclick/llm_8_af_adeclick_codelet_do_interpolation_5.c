#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern int n;
extern double *out;
extern int i;
extern int j;
extern double *y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    for (i = n - 1; i >= 0; i--) {
        double temp = y[i] / matrix[i * n + i];
        // Unroll inner loop by factor of 2 to increase arithmetic density
        for (j = i + 1; j + 1 < n; j += 2) {
            temp -= matrix[j * n + i] * out[j];
            temp -= matrix[(j + 1) * n + i] * out[j + 1];
        }
        // Handle remaining element if n is odd
        if (j < n) {
            temp -= matrix[j * n + i] * out[j];
        }
        out[i] = temp;
    }
}
