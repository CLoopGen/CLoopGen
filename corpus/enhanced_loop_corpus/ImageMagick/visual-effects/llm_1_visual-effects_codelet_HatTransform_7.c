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
    if (extent > 0) {
        kernel[0] = 0.25F * (*p + (*p) + (*q) + (*r));
        p += (ptrdiff_t)stride;
        q += (ptrdiff_t)stride;
        r -= stride;

        for (i = 1; i < (ssize_t)extent; i++) {
            kernel[i] = 0.25F * (*p + (*p) + (*q) + (*r));
            p += (ptrdiff_t)stride;
            q += (ptrdiff_t)stride;
            r -= stride;
        }
    }
}
