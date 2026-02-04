#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t offset;
    for (offset = 0; offset < 8; offset++) {
        dst[offset] = (((A * src[offset] + B * src[offset + 1] + C * src[stride + offset] + D * src[stride + offset + 1] + bias)) >> 6);
    }
    dst += stride;
    src += stride;
}
}
