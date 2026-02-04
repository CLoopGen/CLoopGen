#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double fval[25];
extern double v[12];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern: fval[i] and fval[24-i] becomes strided across iterations
    for (i = 0; i < 12; i += 2) {
        const size_t j0 = 24 - i;
        const size_t j1 = 24 - (i + 1);
        v[i] = fval[i] - fval[j0];
        fval[i] = fval[i] + fval[j0];
        if (i + 1 < 12) {
            v[i + 1] = fval[i + 1] - fval[j1];
            fval[i + 1] = fval[i + 1] + fval[j1];
        }
    }
}
