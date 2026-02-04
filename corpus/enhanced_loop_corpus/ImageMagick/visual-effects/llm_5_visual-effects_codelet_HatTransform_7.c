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
        float temp = *p + *p + *q;
        if (temp < 100.0F) {
            kernel[i] = 0.25F * (temp + *r);
        } else {
            kernel[i] = 0.0F;
        }
        p += (ptrdiff_t)stride;
        q += (ptrdiff_t)stride;
        r -= stride;
    }
}
