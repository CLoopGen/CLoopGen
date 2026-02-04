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
    float temp_kernel[8];
    size_t unroll_factor = 8;
    ssize_t limit = (extent - scale) - (unroll_factor - 1);
    for (; i < (ssize_t)limit; i += unroll_factor) {
        #pragma unroll
        for (size_t j = 0; j < unroll_factor; j++) {
            temp_kernel[j] = 0.25F * (2.F * (*(p + j * stride)) + 
                                      *(p + j * stride - scale * stride) + 
                                      *(p + j * stride + scale * stride));
        }
        for (size_t j = 0; j < unroll_factor; j++) {
            kernel[i + j] = temp_kernel[j];
        }
        p += (ptrdiff_t)(unroll_factor * stride);
    }
    for (; i < (ssize_t)(extent - scale); i++) {
        kernel[i] = 0.25F * (2.F * (*p) + *(p - scale * stride) + *(p + scale * stride));
        p += (ptrdiff_t)stride;
    }
}
