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
    float *p_local = p;
    float *q_local = q;
    float *r_local = r;
    float *k = kernel;
    for (i = 0; i < (ssize_t)scale; i++) {
        float sum = (*p_local) + (*p_local) + (*q_local) + (*r_local);
        k[i] = 0.25F * sum;
        p_local += (ptrdiff_t)stride;
        q_local -= stride;
        r_local += (ptrdiff_t)stride;
    }
}
