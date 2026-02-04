#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t len;
extern uint32_t stride;
extern float c;
extern float s;
extern float *Xptr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len - stride * 2; i += 2) {
        float x1 = Xptr[0];
        float x2 = Xptr[stride];
        float x3 = Xptr[2 * stride];
        float x4 = Xptr[3 * stride];

        Xptr[stride] = c * x2 + s * x1;
        Xptr[3 * stride] = c * x4 + s * x3;
        *Xptr++ = c * x1 - s * x2;
        *Xptr++ = c * x3 - s * x4;
    }
}
