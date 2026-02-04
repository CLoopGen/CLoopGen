#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cheb12[13];
extern double moment[25];
extern double res12;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle odd number of elements
    res12 = 0.0;
    size_t limit = (13 + 1) / 2; // Number of iterations for stride 2 over 13 elements
    for (i = 0; i < limit; i++) {
        size_t idx = 2 * i;
        res12 += cheb12[idx] * moment[idx];
        if (idx + 1 < 13) {
            res12 += cheb12[idx + 1] * moment[idx + 1];
        }
    }
}
