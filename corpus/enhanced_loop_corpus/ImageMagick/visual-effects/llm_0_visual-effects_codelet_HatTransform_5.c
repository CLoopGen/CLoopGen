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
    for (ssize_t outer = 0; outer < (ssize_t)scale; outer += 2) {
        for (ssize_t inner = 0; inner < 2 && (outer + inner) < (ssize_t)scale; inner++) {
            ssize_t idx = outer + inner;
            kernel[idx] = 0.25F * (p[idx * stride] + p[idx * stride] + q[-idx * stride] + r[idx * stride]);
        }
    }
}
