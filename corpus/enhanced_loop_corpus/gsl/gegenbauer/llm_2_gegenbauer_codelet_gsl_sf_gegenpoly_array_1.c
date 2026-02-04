#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmax;
extern double lambda;
extern double x;
extern double *result_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling the loop with stride-1 access
    // This variant assumes nmax is even for simplicity, and processes two elements per iteration
    int k;
    if (nmax >= 2) {
        result_array[2] = (2. * (2 + lambda - 1.) * x * result_array[1] - (2 + 2. * lambda - 2.) * result_array[0]) / 2;
    }
    for (k = 3; k <= nmax - 1; k += 2) {
        // Compute k-th element
        double term1_k = 2. * (k + lambda - 1.) * x * result_array[k - 1];
        double term2_k = (k + 2. * lambda - 2.) * result_array[k - 2];
        result_array[k] = (term1_k - term2_k) / k;

        // Compute (k+1)-th element using updated index
        double term1_next = 2. * (k + 1 + lambda - 1.) * x * result_array[k];
        double term2_next = (k + 1 + 2. * lambda - 2.) * result_array[k - 1];
        result_array[k + 1] = (term1_next - term2_next) / (k + 1);
    }
    // Handle odd nmax case
    if (nmax % 2 == 0 && nmax > 2) {
        double term1_last = 2. * (nmax + lambda - 1.) * x * result_array[nmax - 1];
        double term2_last = (nmax + 2. * lambda - 2.) * result_array[nmax - 2];
        result_array[nmax] = (term1_last - term2_last) / nmax;
    }
}
