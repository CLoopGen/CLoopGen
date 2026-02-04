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
    int temp0, temp1, temp2, temp3;
    for (i = 0; i < h; i++) {
        temp0 = A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1];
        temp1 = A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2];
        temp2 = A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3];
        temp3 = A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4];

        dst[0] = ((temp0 + bias) >> 6);
        dst[1] = ((temp1 + bias) >> 6);
        dst[2] = ((temp2 + bias) >> 6);
        dst[3] = ((temp3 + bias) >> 6);

        dst += stride;
        src += stride;
    }
}
