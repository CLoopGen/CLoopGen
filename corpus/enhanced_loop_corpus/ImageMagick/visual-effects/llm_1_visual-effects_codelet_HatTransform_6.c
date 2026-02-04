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
    if (extent > scale) {
        i = 0;
        for (ssize_t block = 0; block < (extent - scale + 3) / 4; block++) {
            for (ssize_t unroll = 0; unroll < 4 && i < (ssize_t)(extent - scale); i++, unroll++) {
                kernel[i] = 0.25F * (2.F * (*p) + *(p - scale * stride) + *(p + scale * stride));
                p += (ptrdiff_t)stride;
            }
        }
    }
}
