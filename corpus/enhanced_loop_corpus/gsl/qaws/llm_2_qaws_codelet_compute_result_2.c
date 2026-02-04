#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *r;
extern  double *cheb24;
extern size_t i;
extern double res24;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    size_t stride = 2;
    for (i = 0; i < 25; i += stride) {
        res24 += r[i] * cheb24[i];
    }
    for (i = 1; i < 25; i += stride) {
        res24 += r[i] * cheb24[i];
    }
}
