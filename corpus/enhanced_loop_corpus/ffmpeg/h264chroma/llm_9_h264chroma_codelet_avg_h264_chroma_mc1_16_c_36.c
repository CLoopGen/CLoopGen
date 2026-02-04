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
    uint16_t temp1 = A * src[0] + B * src[1];
    uint16_t temp2 = C * src[stride + 0] + D * src[stride + 1];
    uint16_t temp3 = temp1 + temp2;
    uint16_t result = (temp3 + 32) >> 6;
    dst[0] = ((dst[0] + result + 1) >> 1);
    dst += stride;
    src += stride;
}
}
