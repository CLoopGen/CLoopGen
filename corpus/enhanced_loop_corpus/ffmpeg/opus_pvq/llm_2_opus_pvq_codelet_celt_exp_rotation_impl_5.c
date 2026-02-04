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
    float x1 = Xptr[i];
    float x2 = Xptr[i + stride];
    Xptr[i + stride] = c * x2 + s * x1;
    Xptr[i] = c * x1 - s * x2;
}
}
