#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern double *alm;
extern size_t l;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with stride of 2, unrolled to access consecutive indices
    // Instead of writing to alm[2*k] and alm[2*k+1], we write directly to consecutive even-odd pairs
    double *base = alm;
    for (l = 2; l <= lmax; ++l) {
        base[0] = 2. - 1. / (double)l;
        base[1] = -(1. - 1. / (double)l);
        base += 2;
        ++k;
    }
}
