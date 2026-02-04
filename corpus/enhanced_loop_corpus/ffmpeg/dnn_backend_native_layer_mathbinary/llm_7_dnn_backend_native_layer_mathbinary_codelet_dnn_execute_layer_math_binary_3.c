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
    for (int i = 1; i < dims_count; ++i) {
        dst[i] = src[i-1] - src1[i];
    }
    if (dims_count > 0) {
        dst[0] = src[0] - src1[0];
    }
}
