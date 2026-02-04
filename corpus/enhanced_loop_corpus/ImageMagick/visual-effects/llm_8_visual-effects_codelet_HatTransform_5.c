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
    for (i = 0; i < (ssize_t)scale; i += 2) {
        if (i + 1 < (ssize_t)scale) {
            kernel[i]     = 0.25F * (*p + *(p + (ptrdiff_t)stride) + *q + *r);
            kernel[i + 1] = 0.33F * (*(p + (ptrdiff_t)stride) + *(p + 2*(ptrdiff_t)stride) + *(q - stride) + *(r + (ptrdiff_t)stride));
        } else {
            kernel[i] = 0.5F * (*p + *q);
        }
        p += 2 * (ptrdiff_t)stride;
        q -= 2 * stride;
        r += 2 * (ptrdiff_t)stride;
    }
}
