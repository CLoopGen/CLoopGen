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
        float denom = src1[i];
        if (denom > 1e-6f || denom < -1e-6f) {
            dst[i] = src[i] * (1.0f / denom);
        } else {
            dst[i] = 0.0f;
        }
    }
}
