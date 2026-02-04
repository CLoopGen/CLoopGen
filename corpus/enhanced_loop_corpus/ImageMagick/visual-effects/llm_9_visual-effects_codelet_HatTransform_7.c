#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t stride;
extern  size_t extent;
extern float *kernel;
extern  float *restrict p;
extern  float *restrict q;
extern  float *restrict r;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < (ssize_t)extent; i++) {
        float sum1 = *p + *q;
        float sum2 = *p + *r;
        kernel[i] = 0.5F * (sum1 + sum2) * 0.5F;
        kernel[i] += 0.1F * (*p - *r);
        p += (ptrdiff_t)stride;
        q += (ptrdiff_t)stride;
        r -= stride;
    }
}
