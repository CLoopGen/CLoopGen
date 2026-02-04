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
    float acc = 0.0F;
    float factor = 1.F / (2.F * 2147483647);
    for (i = 0; i < len; i++) {
        acc += src[i];
        dst[i] = acc * factor;
    }
}
