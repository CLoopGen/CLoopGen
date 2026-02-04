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
for (i = 0; i < h; i++) {
    int val;
    val = (A * src[0] + B * src[1] + C * src[stride] + D * src[stride + 1] + 32) >> 6;
    dst[0] = (dst[0] + val + 1) >> 1;

    // Reduced arithmetic: skip second assignment and use simpler update
    dst += stride;
    src += stride;
}
}
