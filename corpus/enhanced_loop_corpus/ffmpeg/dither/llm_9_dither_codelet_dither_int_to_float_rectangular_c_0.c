#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern int *src;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale = 1.F / (2.F * 2147483647);
    float offset = 0.001F;
    for (i = 0; i < len; i++) {
        float temp = src[i] * scale;
        dst[i] = temp + offset; // Increased arithmetic intensity
    }
}
