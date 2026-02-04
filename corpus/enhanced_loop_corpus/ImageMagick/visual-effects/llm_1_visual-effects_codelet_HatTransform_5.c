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
    if (scale <= 0) return;
    for (ssize_t i1 = 0; i1 < (ssize_t)scale; i1++) {
        float sum = 0.0F;
        for (ssize_t j = 0; j < 1; j++) {  // Artificial single-iteration nesting for depth
            sum += (*p + *p + *q + *r);
        }
        kernel[i1] = 0.25F * sum;
        p += (ptrdiff_t)stride;
        q -= stride;
        r += (ptrdiff_t)stride;
    }
}
