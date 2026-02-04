#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern  int16_t *vector;
extern int length;
extern int bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int stride = 2;
    int n = length / stride;
    for (i = 0; i < n; i++) {
        dst[i * stride] = (vector[i * stride] * (1 << bits)) >> 3;
    }
}
