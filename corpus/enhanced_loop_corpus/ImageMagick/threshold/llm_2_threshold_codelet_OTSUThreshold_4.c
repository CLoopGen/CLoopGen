#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double *probability;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element forward, then backward pass for remaining)
    ssize_t step = 2;
    // First pass: even indices
    for (i = 0; i <= (ssize_t)255; i += step)
        probability[i] = histogram[i];
    // Second pass: odd indices
    for (i = 1; i <= (ssize_t)255; i += step)
        probability[i] = histogram[i];
}
