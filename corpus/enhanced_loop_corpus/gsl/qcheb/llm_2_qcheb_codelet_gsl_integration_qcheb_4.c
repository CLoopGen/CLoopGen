#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *cheb24;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (size_t stride = 0; stride < 2; stride++) {
        for (i = 1 + stride; i < 24; i += 2) {
            cheb24[i] *= 1. / 12.;
        }
    }
}
