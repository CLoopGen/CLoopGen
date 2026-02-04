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
    for (; i < (ssize_t)extent; i += 2) {
        if (i + 1 < (ssize_t)extent) {
            kernel[i] = 0.25F * (*p + *(p + (ptrdiff_t)stride) + *q + *r);
            kernel[i + 1] = 0.25F * (*(p + (ptrdiff_t)stride) + *(p + 2*(ptrdiff_t)stride) + *(q + (ptrdiff_t)stride) + *(r - stride));
        } else {
            kernel[i] = 0.25F * (*p + *p + *q + *r);
        }
        p += 2 * (ptrdiff_t)stride;
        q += 2 * (ptrdiff_t)stride;
        r -= 2 * stride;
    }
}
