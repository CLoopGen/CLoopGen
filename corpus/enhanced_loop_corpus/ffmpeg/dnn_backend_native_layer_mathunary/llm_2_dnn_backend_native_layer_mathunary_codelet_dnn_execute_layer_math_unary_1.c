#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dims_count;
extern  float *src;
extern float *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int i = 0; i < dims_count; i += 2) {
        dst[i] = (src[i] >= 0) ? src[i] : -src[i];
        if (i + 1 < dims_count) {
            dst[i + 1] = (src[i + 1] >= 0) ? src[i + 1] : -src[i + 1];
        }
    }
}
