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
        if (src[i] == 0.0f || src1[i] == 0.0f) {
            dst[i] = 0.0f;
            continue;
        }
        dst[i] = src[i] * src1[i];
    }
}
