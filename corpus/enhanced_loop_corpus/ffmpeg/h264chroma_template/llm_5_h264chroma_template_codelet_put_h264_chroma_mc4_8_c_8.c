#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        int coeff = A;
        if (coeff > 16) {
            dst[0] = (((coeff * src[0]) + 32) >> 6);
            dst[1] = (((coeff * src[1]) + 32) >> 6);
        } else {
            dst[0] = src[0];
            dst[1] = src[1];
        }
        dst[2] = (((coeff * src[2]) + 32) >> 6);
        dst[3] = (((coeff * src[3]) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
