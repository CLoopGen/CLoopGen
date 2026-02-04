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
    for (i = 0; i < h; i++) {
        uint8_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3];
        uint8_t temp4 = src[4], temp5 = src[5], temp6 = src[6], temp7 = src[7];
        uint8_t o0 = step + 0, o1 = step + 1, o2 = step + 2, o3 = step + 3;
        uint8_t o4 = step + 4, o5 = step + 5, o6 = step + 6, o7 = step + 7;

        dst[0] = ((A * temp0 + E * src[o0] + bias) >> 6);
        dst[1] = ((A * temp1 + E * src[o1] + bias) >> 6);
        dst[2] = ((A * temp2 + E * src[o2] + bias) >> 6);
        dst[3] = ((A * temp3 + E * src[o3] + bias) >> 6);
        dst[4] = ((A * temp4 + E * src[o4] + bias) >> 6);
        dst[5] = ((A * temp5 + E * src[o5] + bias) >> 6);
        dst[6] = ((A * temp6 + E * src[o6] + bias) >> 6);
        dst[7] = ((A * temp7 + E * src[o7] + bias) >> 6);

        dst += stride;
        src += stride;
    }
}
