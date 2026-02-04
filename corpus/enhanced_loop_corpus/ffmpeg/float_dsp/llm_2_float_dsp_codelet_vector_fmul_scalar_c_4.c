#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src;
extern float mul;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int n = len / stride;
    for (i = 0; i < n; i++) {
        dst[i * stride] = src[i * stride] * mul;
    }
    // Handle remaining elements if len is not divisible by stride
    for (i = n * stride; i < len; i++) {
        dst[i] = src[i] * mul;
    }
}
