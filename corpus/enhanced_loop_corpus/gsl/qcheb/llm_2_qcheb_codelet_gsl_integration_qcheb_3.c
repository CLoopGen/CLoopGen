#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *cheb12;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order)
    for (i = 11; i > 0; i -= 2) {
        cheb12[i] *= 1. / 6.;
    }
    // Handle remaining element if needed (i=1 when starting from odd index)
    if (i == 1) {
        cheb12[i] *= 1. / 6.;
    }
}
