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
        dst[i] = src[i] * src1[i] + src[i] * src1[i]; // Doubled arithmetic operations: two multiplies and one add
    }
}
