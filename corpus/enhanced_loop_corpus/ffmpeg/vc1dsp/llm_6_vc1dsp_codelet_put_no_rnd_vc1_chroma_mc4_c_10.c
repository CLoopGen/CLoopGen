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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (i = 0; i < h; i++) {
        int temp0 = A * local_src[0] + B * local_src[1] + C * local_src[stride + 0] + D * local_src[stride + 1];
        int temp1 = A * local_src[1] + B * local_src[2] + C * local_src[stride + 1] + D * local_src[stride + 2];
        int temp2 = A * local_src[2] + B * local_src[3] + C * local_src[stride + 2] + D * local_src[stride + 3];
        int temp3 = A * local_src[3] + B * local_src[4] + C * local_src[stride + 3] + D * local_src[stride + 4];

        local_dst[0] = (temp0 + 28) >> 6;
        local_dst[1] = (temp1 + 28) >> 6;
        local_dst[2] = (temp2 + 28) >> 6;
        local_dst[3] = (temp3 + 28) >> 6;

        local_dst += stride;
        local_src += stride;
    }
}
