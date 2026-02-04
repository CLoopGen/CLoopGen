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
    float *p_next, *q_next, *r_next;
    for (i = 0; i < (ssize_t)scale; i++) {
        p_next = p + (ptrdiff_t)stride;
        q_next = q - stride;
        r_next = r + (ptrdiff_t)stride;
        kernel[i] = 0.25F * (*p + *p + *q + *r);
        p = p_next;
        q = q_next;
        r = r_next;
    }
}
