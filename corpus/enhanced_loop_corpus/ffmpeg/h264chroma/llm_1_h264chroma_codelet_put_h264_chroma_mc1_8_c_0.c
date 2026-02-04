#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < h / 2; outer++) {
    for (int inner = 0; inner < 2; inner++) {
        int i = outer * 2 + inner;
        if (i >= h) break;
        dst[0] = ((((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1])) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
}
