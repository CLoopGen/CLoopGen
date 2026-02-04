#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < h * 2; i++) {
        int offset = (i % 2) * 2;
        dst[0] = ((((A * src[0 + offset] + B * src[1 + offset] + C * src[stride + 0 + offset] + D * src[stride + 1 + offset])) + 32) >> 6);
        dst[1] = ((((A * src[1 + offset] + B * src[2 + offset] + C * src[stride + 1 + offset] + D * src[stride + 2 + offset])) + 32) >> 6);
        dst += stride / 2;
        src += stride / 2;
    }
}
