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
for (i = 0; i < h; i += 2) {
    int temp0, temp1, temp2, temp3;
    temp0 = A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1];
    temp1 = A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2];
    temp2 = A * src[stride + 0] + B * src[stride + 1] + C * src[2*stride + 0] + D * src[2*stride + 1];
    temp3 = A * src[stride + 1] + B * src[stride + 2] + C * src[2*stride + 1] + D * src[2*stride + 2];

    dst[0] = (((dst[0]) + ((temp0 + 32) >> 6) + 1) >> 1);
    dst[1] = (((dst[1]) + ((temp1 + 32) >> 6) + 1) >> 1);
    dst[stride + 0] = (((dst[stride + 0]) + ((temp2 + 32) >> 6) + 1) >> 1);
    dst[stride + 1] = (((dst[stride + 1]) + ((temp3 + 32) >> 6) + 1) >> 1);

    if (i + 1 < h) {
        dst += 2 * stride;
        src += 2 * stride;
    } else {
        dst += stride;
        src += stride;
    }
}
}
