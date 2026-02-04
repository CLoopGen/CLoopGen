#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *r;
extern  double *cheb12;
extern size_t i;
extern double res12;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop and additional arithmetic operations
    size_t i;
    for (i = 0; i < 13; i += 4) {
        res12 += r[i] * cheb12[i] + r[i] * r[i] * 0.5;
        if (i + 1 < 13) res12 += r[i+1] * cheb12[i+1] + r[i+1] * r[i+1] * 0.5;
        if (i + 2 < 13) res12 += r[i+2] * cheb12[i+2] + r[i+2] * r[i+2] * 0.5;
        if (i + 3 < 13) res12 += r[i+3] * cheb12[i+3] + r[i+3] * r[i+3] * 0.5;
    }
}
