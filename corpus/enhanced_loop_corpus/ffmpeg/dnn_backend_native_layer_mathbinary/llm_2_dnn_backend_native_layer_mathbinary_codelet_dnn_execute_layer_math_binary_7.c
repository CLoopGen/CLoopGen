#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dims_count;
extern  float *src;
extern float *dst;
extern  float *src1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in two passes to cover all indices
    int stride = 2;
    for (int i = 0; i < dims_count; i += stride) {
        dst[i] = src[i] * src1[i];
    }
    for (int i = 1; i < dims_count; i += stride) {
        dst[i] = src[i] * src1[i];
    }
}
