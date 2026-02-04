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
for (i = len - 2 * stride - 1; i >= 0; i--) {
    float x1 = Xptr[0];
    float x2 = Xptr[stride];
    float temp1, temp2;

    temp1 = c * x2 + s * x1;
    temp2 = c * x1 - s * x2;

    Xptr[stride] = temp1;
    *Xptr-- = temp2;

    // Additional computational work to increase arithmetic intensity
    temp1 = temp1 * temp2 + c;
    temp2 = temp2 * temp2 - s;
    c = temp1 * 0.5f;
    s = temp2 * 0.5f;
}
}
