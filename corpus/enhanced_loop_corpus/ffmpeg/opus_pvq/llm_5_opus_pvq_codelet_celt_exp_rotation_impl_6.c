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
        if (x1 > 0.0f && x2 < 0.0f) {
            Xptr[stride] = c * x2 + s * x1;
            *Xptr-- = c * x1 - s * x2;
        } else if (x1 <= 0.0f) {
            *Xptr-- = (c + s) * x1;
        } else {
            Xptr[stride] = (c - s) * x2;
            Xptr--;
        }
    }
}
