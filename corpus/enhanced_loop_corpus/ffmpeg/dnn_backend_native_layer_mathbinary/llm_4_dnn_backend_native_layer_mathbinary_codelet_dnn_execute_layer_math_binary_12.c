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
        float a = src[i];
        float b = src1[i];
        if (a <= b) {
            dst[i] = a;
        } else {
            dst[i] = b;
        }
    }
}
