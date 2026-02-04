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
    uint16_t temp0 = src[0], temp1 = src[1];
    uint16_t temp2 = src[2], temp3 = src[3];
    uint16_t s0 = A * temp0 + E * src[step + 0];
    uint16_t s1 = A * temp1 + E * src[step + 1];
    uint16_t s2 = A * temp2 + E * src[step + 2];
    uint16_t s3 = A * temp3 + E * src[step + 3];

    dst[0] = ((dst[0] + ((s0 + 32) >> 6) + 1) >> 1);
    dst[1] = ((dst[1] + ((s1 + 32) >> 6) + 1) >> 1);
    dst[2] = ((dst[2] + ((s2 + 32) >> 6) + 1) >> 1);
    dst[3] = ((dst[3] + ((s3 + 32) >> 6) + 1) >> 1);

    dst += stride;
    src += stride;
}
}
