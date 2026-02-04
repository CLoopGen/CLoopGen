#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp0, temp1, temp2, temp3;
    for (i = 0; i < h; i++) {
        temp0 = A * src[0];
        temp1 = A * src[1];
        temp2 = A * src[2];
        temp3 = A * src[3];
        dst[0] = ((temp0 + E * src[step + 0] + 32) >> 6);
        dst[1] = ((temp1 + E * src[step + 1] + 32) >> 6);
        dst[2] = ((temp2 + E * src[step + 2] + 32) >> 6);
        dst[3] = ((temp3 + E * src[step + 3] + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
