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
    // Variant 2: Strided memory access — process every other element first, then fill in gaps
    // First pass: compute even indices (assuming k starts at 2 and increases by 2)
    int k;
    for (k = 2; k <= nmax; k += 2) {
        double term1 = 2. * (k + lambda - 1.) * x * result_array[k - 1];
        double term2 = (k + 2. * lambda - 2.) * result_array[k - 2];
        result_array[k] = (term1 - term2) / k;
    }
    // Second pass: compute odd indices in increasing order
    for (k = 3; k <= nmax; k += 2) {
        double term1 = 2. * (k + lambda - 1.) * x * result_array[k - 1];
        double term2 = (k + 2. * lambda - 2.) * result_array[k - 2];
        result_array[k] = (term1 - term2) / k;
    }
}
