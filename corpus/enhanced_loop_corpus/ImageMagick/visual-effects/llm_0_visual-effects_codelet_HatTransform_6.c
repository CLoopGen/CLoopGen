#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t stride;
extern  size_t extent;
extern  size_t scale;
extern float *kernel;
extern  float *restrict p;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t outer = 0; outer < (ssize_t)(extent - scale); outer++) {
        for (i = outer; i < outer + 1 && i < (ssize_t)(extent - scale); i++) {
            kernel[i] = 0.25F * (2.F * (*p) + *(p - scale * stride) + *(p + scale * stride));
            p += (ptrdiff_t)stride;
        }
    }
}
