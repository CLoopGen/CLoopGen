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
    float prev_x1 = 0.0f;
    for (i = 0; i < len - stride; i++) {
        float x1 = (i == 0) ? Xptr[0] : prev_x1;
        float x2 = Xptr[stride];
        prev_x1 = c * x1 - s * x2;
        Xptr[stride] = c * x2 + s * x1;
        *Xptr++ = prev_x1;
    }
}
