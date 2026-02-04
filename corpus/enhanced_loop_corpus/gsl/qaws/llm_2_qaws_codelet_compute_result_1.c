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
    // Variant 1: Strided memory access (stride of 2, unrolled to handle odd count)
    size_t i;
    for (i = 0; i < 13; i += 2) {
        res12 += r[i] * cheb12[i];
        if (i + 1 < 13) {
            res12 += r[i+1] * cheb12[i+1];
        }
    }
}
