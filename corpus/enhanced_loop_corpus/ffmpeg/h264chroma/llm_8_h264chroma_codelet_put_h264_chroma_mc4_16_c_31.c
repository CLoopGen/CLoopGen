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
    int val0 = A * src[0] + E * src[step + 0];
    int val1 = A * src[1] + E * src[step + 1];
    int val2 = A * src[2] + E * src[step + 2];
    int val3 = A * src[3] + E * src[step + 3];
    dst[0] = (val0 + 32) >> 6;
    dst[1] = (val1 + 32) >> 6;
    dst[2] = (val2 + 32) >> 6;
    dst[3] = (val3 + 32) >> 6;
    dst += stride;
    src += stride;
}
}
