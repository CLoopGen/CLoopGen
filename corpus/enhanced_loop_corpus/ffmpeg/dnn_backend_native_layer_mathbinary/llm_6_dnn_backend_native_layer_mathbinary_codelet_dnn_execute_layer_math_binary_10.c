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
    float temp = 0.0f;
    for (int i = 0; i < dims_count; ++i) {
        temp = src[i] / src1[i];
        dst[i] = temp;
    }
}
