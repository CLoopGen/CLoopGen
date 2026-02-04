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
    for (int i = 0; i < dims_count * 2; i += 2) {
        if (i < dims_count) {
            dst[i] = src[i] - src1[i];
        }
        if (i + 1 < dims_count) {
            dst[i + 1] = src[i + 1] - src1[i + 1];
        }
    }
}
