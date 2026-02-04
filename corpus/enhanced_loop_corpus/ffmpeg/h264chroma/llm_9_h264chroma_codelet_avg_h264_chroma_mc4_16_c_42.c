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
for (i = 0; i < h * 2; i++) {
    int j = i % 4;
    dst[j] = (((dst[j]) + ((((A * src[j] + B * src[j+1] + C * src[stride + j] + D * src[stride + j+1])) + 32) >> 6) + 1) >> 1);
    if ((i & 3) == 3) {
        dst += stride;
        src += stride;
    }
}
}
