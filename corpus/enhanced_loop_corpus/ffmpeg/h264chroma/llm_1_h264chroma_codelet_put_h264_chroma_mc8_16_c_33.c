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
    int j = 0;
    for (; j < 4; j++) {
        dst[j]         = ((((A * src[j] + B * src[j+1] + C * src[stride + j] + D * src[stride + j + 1])) + 32) >> 6);
        dst[j + 4]     = ((((A * src[j + 4] + B * src[j + 5] + C * src[stride + j + 4] + D * src[stride + j + 5])) + 32) >> 6);
    }
    dst += stride;
    src += stride;
}
}
