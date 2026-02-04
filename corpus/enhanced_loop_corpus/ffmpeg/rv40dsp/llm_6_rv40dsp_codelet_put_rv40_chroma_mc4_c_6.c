#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern int i;
extern int bias;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < h; i++) {
        uint8_t temp0 = src[0];
        uint8_t temp1 = src[1];
        uint8_t temp2 = src[2];
        uint8_t temp3 = src[3];
        dst[0] = (((A * temp0 + E * src[step + 0] + bias)) >> 6);
        dst[1] = (((A * temp1 + E * src[step + 1] + bias)) >> 6);
        dst[2] = (((A * temp2 + E * src[step + 2] + bias)) >> 6);
        dst[3] = (((A * temp3 + E * src[step + 3] + bias)) >> 6);
        dst += stride;
        src += stride;
    }
}
