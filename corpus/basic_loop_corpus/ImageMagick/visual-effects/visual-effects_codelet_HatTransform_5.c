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
for (i = 0; i < (ssize_t)scale; i++) {
    kernel[i] = 0.25F * (*p + (*p) + (*q) + (*r));
    p += (ptrdiff_t)stride;
    q -= stride;
    r += (ptrdiff_t)stride;
}

}
