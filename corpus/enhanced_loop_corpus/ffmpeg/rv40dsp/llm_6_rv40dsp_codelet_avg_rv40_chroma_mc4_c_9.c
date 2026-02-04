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
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (i = 0; i < h; i++) {
        int temp0 = (A * local_src[0] + B * local_src[1] + C * local_src[stride + 0] + D * local_src[stride + 1] + bias) >> 6;
        int temp1 = (A * local_src[1] + B * local_src[2] + C * local_src[stride + 1] + D * local_src[stride + 2] + bias) >> 6;
        int temp2 = (A * local_src[2] + B * local_src[3] + C * local_src[stride + 2] + D * local_src[stride + 3] + bias) >> 6;
        int temp3 = (A * local_src[3] + B * local_src[4] + C * local_src[stride + 3] + D * local_src[stride + 4] + bias) >> 6;

        local_dst[0] = ((local_dst[0] + temp0 + 1) >> 1);
        local_dst[1] = ((local_dst[1] + temp1 + 1) >> 1);
        local_dst[2] = ((local_dst[2] + temp2 + 1) >> 1);
        local_dst[3] = ((local_dst[3] + temp3 + 1) >> 1);

        local_dst += stride;
        local_src += stride;
    }
}
