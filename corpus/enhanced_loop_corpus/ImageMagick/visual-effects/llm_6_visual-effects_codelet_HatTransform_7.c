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
    float temp_sum = 0.0F;
    for (; i < (ssize_t)extent; i++) {
        temp_sum = *p + *q + *r;
        kernel[i] = 0.25F * (temp_sum + *p);
        p += (ptrdiff_t)stride;
        q += (ptrdiff_t)stride;
        r -= stride;
    }
}
