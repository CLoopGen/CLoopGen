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
for (i = 0; i < h; i += 2) {
    int j;
    for (j = 0; j < 8; j++) {
        dst[j] = (((dst[j]) + (((A * src[j] + E * src[step + j] + bias)) >> 6) + 1) >> 1);
    }
    for (j = 0; j < 8; j++) {
        dst[stride + j] = (((dst[stride + j]) + (((A * src[stride + j] + E * src[step + stride + j] + bias)) >> 6) + 1) >> 1);
    }
    dst += 2 * stride;
    src += 2 * stride;
}
}
