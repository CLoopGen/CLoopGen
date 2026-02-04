#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *moment;
extern double cheb12[13];
extern double res12_cos;
extern double res12_sin;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration and offset indexing
    size_t indices[6];
    for (size_t idx = 0; idx < 6; idx++) {
        indices[idx] = 10 - 2 * idx;
    }
    for (i = 0; i < 6; i++) {
        size_t k = indices[i];
        res12_cos += cheb12[k] * moment[k];
        res12_sin += cheb12[k + 1] * moment[k + 1];
    }
}
