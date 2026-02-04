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
    int val0 = A * src[0] + E * src[step + 0] + bias;
    int val1 = A * src[1] + E * src[step + 1] + bias;
    int val2 = A * src[2] + E * src[step + 2] + bias;
    int val3 = A * src[3] + E * src[step + 3] + bias;
    dst[0] = ((dst[0] + (val0 >> 6) + 1) >> 1);
    dst[1] = ((dst[1] + (val1 >> 6) + 1) >> 1);
    dst[2] = ((dst[2] + (val2 >> 6) + 1) >> 1);
    dst[3] = ((dst[3] + (val3 >> 6) + 1) >> 1);
    dst += stride;
    src += stride;
}
}
