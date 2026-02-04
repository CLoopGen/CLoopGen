#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *coeff;
extern int size;
extern double x;
extern double sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (2x unroll) and reduced trip count
    // This decreases the number of iterations by approximately half while increasing arithmetic per iteration
    sum = sum * x + coeff[size - 2]; // Handle last element if size is odd
    for (i = size - 3; i >= 1; i -= 2) {
        sum = sum * x * x + coeff[i] * x + coeff[i-1];
    }
    if (i == 0) {
        sum = sum * x + coeff[0];
    }
}
