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
    int val0 = A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] + bias;
    int val1 = A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] + bias;
    int val2 = A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] + bias;
    int val3 = A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] + bias;

    dst[0] = ((dst[0] + ((val0 >> 6) + 1)) >> 1);
    dst[1] = ((dst[1] + ((val1 >> 6) + 1)) >> 1);
    dst[2] = ((dst[2] + ((val2 >> 6) + 1)) >> 1);
    dst[3] = ((dst[3] + ((val3 >> 6) + 1)) >> 1);

    dst += stride;
    src += stride;
}
}
