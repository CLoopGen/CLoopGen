#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float beta;
extern float *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided but unrolled by factor of 2 for improved memory access pattern
    int stride = incY;
    int idx = iy;
    float b = beta;
    int limit = lenY - (lenY % 2); // Make it even for safe unrolling
    for (i = 0; i < limit; i += 2) {
        Y[idx] *= b;
        Y[idx + stride] *= b;
        idx += 2 * stride;
    }
    // Handle remaining element if lenY is odd
    if (i < lenY) {
        Y[idx] *= b;
    }
}
