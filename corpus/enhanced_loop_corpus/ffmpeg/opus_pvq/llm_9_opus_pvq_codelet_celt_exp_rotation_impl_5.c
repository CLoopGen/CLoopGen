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
    for (i = 0; i < len - stride; i++) {
        float x1 = Xptr[0];
        float x2 = Xptr[stride];
        float t1 = c * x1 - s * x2;
        float t2 = c * x2 + s * x1;

        // Additional computational work to increase arithmetic intensity
        t1 = t1 * t1 + c;
        t2 = t2 * t2 + s;

        Xptr[stride] = t2;
        *Xptr++ = t1;
    }
}
