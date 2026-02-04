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
    int i;
    for (i = 0; i < len * 2; i++) {
        int idx = i / 2;
        dst[idx] = (src[idx] * mul) + (src[idx] * mul * 0.1f) - (mul * 0.05f);
    }
}
