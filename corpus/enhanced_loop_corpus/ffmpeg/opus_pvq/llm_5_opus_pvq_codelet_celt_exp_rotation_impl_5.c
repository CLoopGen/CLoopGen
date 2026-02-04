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
    for (i = 0; i < len - stride && stride != 0; i++) {
        float x1 = Xptr[0];
        float x2 = Xptr[stride];
        if (i % 2 == 0) {
            Xptr[stride] = c * x2 + s * x1;
            *Xptr++ = c * x1 - s * x2;
        } else {
            Xptr[stride] = s * x2 - c * x1;
            *Xptr++ = s * x1 + c * x2;
        }
    }
}
