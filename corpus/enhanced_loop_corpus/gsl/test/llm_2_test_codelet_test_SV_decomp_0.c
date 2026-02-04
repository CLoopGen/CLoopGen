#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double lower;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, then handle remainder)
    int stride = 2;
    int limit = (9 + stride - 1) / stride * stride; // Round up to next multiple of stride
    for (i = 0; i < limit; i += stride) {
        if (i < 9) {
            a[i] = lower;
        }
    }
}
