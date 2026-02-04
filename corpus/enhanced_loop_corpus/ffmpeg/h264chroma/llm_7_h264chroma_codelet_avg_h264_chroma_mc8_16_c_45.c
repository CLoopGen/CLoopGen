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
for (i = 0; i < h; i++) {
    int offset = 0;
    for (int j = 0; j < 8; j++) {
        dst[offset] = (((dst[offset]) + ((((A * src[offset] + B * src[offset + 1] + C * src[stride + offset] + D * src[stride + offset + 1])) + 32) >> 6) + 1) >> 1);
        offset++;
    }
    dst += stride;
    src += stride;
}
}
