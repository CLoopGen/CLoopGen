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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint16_t s0 = src[0];
    uint16_t s1 = src[1];
    int prod0 = A * s0;
    int prod1 = A * s1;
    int biased0 = prod0 + 32;
    int biased1 = prod1 + 32;
    dst[0] = biased0 >> 6;
    dst[1] = biased1 >> 6;
    dst += stride;
    src += stride;
}
}
