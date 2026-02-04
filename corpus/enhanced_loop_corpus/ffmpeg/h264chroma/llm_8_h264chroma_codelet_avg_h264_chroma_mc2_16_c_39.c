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
    int val0 = A * src[0] + B * src[1];
    int val1 = C * src[stride + 0] + D * src[stride + 1];
    dst[0] = ((dst[0] + (((val0 + val1 + 32) >> 6) + 1)) >> 1);
    
    int val2 = A * src[1] + B * src[2];
    int val3 = C * src[stride + 1] + D * src[stride + 2];
    dst[1] = ((dst[1] + (((val2 + val3 + 32) >> 6) + 1)) >> 1);

    dst += stride;
    src += stride;
}
}
