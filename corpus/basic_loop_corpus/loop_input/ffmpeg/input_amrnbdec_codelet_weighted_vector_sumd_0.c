#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *out;
double *in_a;
double *in_b;
double weight_coeff_a;
double weight_coeff_b;
int length;
int i;

void init_vars() {
    // Set coefficients
    weight_coeff_a = 0.4;
    weight_coeff_b = 0.6;

    // Set array length to achieve ~100ms computation time
    // Assuming ~1ns per operation, 100e6 operations ≈ 100ms
    length = 25000000;  // 25 million elements, ~200 MB total data

    // Allocate arrays
    in_a = (double*)aligned_alloc(32, length * sizeof(double));
    in_b = (double*)aligned_alloc(32, length * sizeof(double));
    out = (double*)aligned_alloc(32, length * sizeof(double));

    // Initialize input arrays with sample values
    for (int j = 0; j < length; j++) {
        in_a[j] = (double)(j % 100) + 1.0;
        in_b[j] = (double)(j % 150) - 75.0;
    }
}