#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  int32_t *src;
extern float mul;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len; i += 2)
        dst[i] = src[i] * mul;
}
