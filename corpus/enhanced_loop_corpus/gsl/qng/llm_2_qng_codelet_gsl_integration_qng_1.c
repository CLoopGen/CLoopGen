#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double w87a[21];
extern double savfun[21];
extern double res87;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    // Access pattern: k = 0, 2, 4, ..., 20 (even indices only), then handle odd index if array size is odd
    res87 = 0.0;
    int i;
    for (i = 0; i < 21; i += 2) {
        res87 += savfun[i] * w87a[i];
    }
    for (i = 1; i < 21; i += 2) {
        res87 += savfun[i] * w87a[i];
    }
}
