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
    float prev_kernel = 0.0F;
    for (; i < (ssize_t)extent; i++) {
        float current_val = 0.25F * (*p + *p + *q + *r);
        kernel[i] = current_val + prev_kernel;
        prev_kernel = current_val;
        p += (ptrdiff_t)stride;
        q += (ptrdiff_t)stride;
        r -= stride;
    }
}
