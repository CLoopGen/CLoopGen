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
    for (int i = 0; i < dims_count; ++i) {
        float inv = 1.0f / src1[i];
        dst[i] = src[i] * inv + src1[i] * src[i];
    }
}
