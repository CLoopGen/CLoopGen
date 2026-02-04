#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x_lp;
extern int len;
extern float x_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *src = x_lp;
    float *dst = x_lp4;
    int n = len >> 2;
    for (int j = 0; j < n; j++) {
        *dst++ = *src;
        src += 2;
    }
}
