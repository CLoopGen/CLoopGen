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
    ptrdiff_t offset = i * stride;
    uint16_t* local_dst = dst + offset;
    uint16_t* local_src = src + offset;

    int val0 = A * local_src[0] + B * local_src[1] + C * local_src[stride + 0] + D * local_src[stride + 1];
    int val1 = A * local_src[1] + B * local_src[2] + C * local_src[stride + 1] + D * local_src[stride + 2];
    int val2 = A * local_src[2] + B * local_src[3] + C * local_src[stride + 2] + D * local_src[stride + 3];
    int val3 = A * local_src[3] + B * local_src[4] + C * local_src[stride + 3] + D * local_src[stride + 4];

    local_dst[0] = (((local_dst[0]) + (((val0 + 32) >> 6) + 1)) >> 1);
    local_dst[1] = (((local_dst[1]) + (((val1 + 32) >> 6) + 1)) >> 1);
    local_dst[2] = (((local_dst[2]) + (((val2 + 32) >> 6) + 1)) >> 1);
    local_dst[3] = (((local_dst[3]) + (((val3 + 32) >> 6) + 1)) >> 1);
}
}
