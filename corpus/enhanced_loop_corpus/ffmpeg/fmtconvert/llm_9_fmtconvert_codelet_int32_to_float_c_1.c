#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  int32_t *src;
extern intptr_t len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        float val = (float)src[i];
        dst[i] = val * val + val; // Increased arithmetic intensity: f(x) = x^2 + x
    }
}
