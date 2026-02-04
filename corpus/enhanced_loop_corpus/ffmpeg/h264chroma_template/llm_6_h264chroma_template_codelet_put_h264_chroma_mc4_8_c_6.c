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
for (i = 0; i < h; i++) {
    uint8_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3], temp4 = src[4];
    uint8_t temp_stride0 = src[stride + 0], temp_stride1 = src[stride + 1];
    uint8_t temp_stride2 = src[stride + 2], temp_stride3 = src[stride + 3], temp_stride4 = src[stride + 4];

    dst[0] = ((((A * temp0 + B * temp1 + C * temp_stride0 + D * temp_stride1)) + 32) >> 6);
    dst[1] = ((((A * temp1 + B * temp2 + C * temp_stride1 + D * temp_stride2)) + 32) >> 6);
    dst[2] = ((((A * temp2 + B * temp3 + C * temp_stride2 + D * temp_stride3)) + 32) >> 6);
    dst[3] = ((((A * temp3 + B * temp4 + C * temp_stride3 + D * temp_stride4)) + 32) >> 6);

    dst += stride;
    src += stride;
}
}
