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
for (i = 0; i < h; i++) {
    uint16_t temp0 = ((A * src[0] + E * src[step + 0]) + 32) >> 6;
    uint16_t temp1 = ((A * src[1] + E * src[step + 1]) + 32) >> 6;
    uint16_t temp2 = ((A * src[2] + E * src[step + 2]) + 32) >> 6;
    uint16_t temp3 = ((A * src[3] + E * src[step + 3]) + 32) >> 6;
    uint16_t temp4 = ((A * src[4] + E * src[step + 4]) + 32) >> 6;
    uint16_t temp5 = ((A * src[5] + E * src[step + 5]) + 32) >> 6;
    uint16_t temp6 = ((A * src[6] + E * src[step + 6]) + 32) >> 6;
    uint16_t temp7 = ((A * src[7] + E * src[step + 7]) + 32) >> 6;

    dst[0] = ((dst[0] + temp0 + 1) >> 1);
    dst[1] = ((dst[1] + temp1 + 1) >> 1);
    dst[2] = ((dst[2] + temp2 + 1) >> 1);
    dst[3] = ((dst[3] + temp3 + 1) >> 1);
    dst[4] = ((dst[4] + temp4 + 1) >> 1);
    dst[5] = ((dst[5] + temp5 + 1) >> 1);
    dst[6] = ((dst[6] + temp6 + 1) >> 1);
    dst[7] = ((dst[7] + temp7 + 1) >> 1);

    dst += stride;
    src += stride;
}
}
