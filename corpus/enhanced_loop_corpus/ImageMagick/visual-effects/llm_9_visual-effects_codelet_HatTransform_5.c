#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t stride;
extern  size_t scale;
extern float *kernel;
extern  float *restrict p;
extern  float *restrict q;
extern  float *restrict r;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)(scale >> 1); i++) {
        float sum1 = *p + *q;
        float sum2 = *(p + (ptrdiff_t)stride) + *(q - stride);
        kernel[2*i]   = 0.25F * (sum1 + sum1);
        kernel[2*i+1] = 0.25F * (sum2 + sum2);
        p += (ptrdiff_t)stride;
        q -= stride;
        r += (ptrdiff_t)stride;
    }
}
