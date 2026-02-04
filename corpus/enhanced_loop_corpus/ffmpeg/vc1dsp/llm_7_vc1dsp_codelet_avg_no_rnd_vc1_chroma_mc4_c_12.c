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
uint8_t prev_dst0 = 0, prev_dst1 = 0, prev_dst2 = 0, prev_dst3 = 0;
for (i = 0; i < h; i++) {
    int val0 = (A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] + 28) >> 6;
    int val1 = (A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] + 28) >> 6;
    int val2 = (A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] + 28) >> 6;
    int val3 = (A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] + 28) >> 6;

    uint8_t new_dst0 = ((prev_dst0 + val0 + 1) >> 1);
    uint8_t new_dst1 = ((prev_dst1 + val1 + 1) >> 1);
    uint8_t new_dst2 = ((prev_dst2 + val2 + 1) >> 1);
    uint8_t new_dst3 = ((prev_dst3 + val3 + 1) >> 1);

    dst[0] = new_dst0;
    dst[1] = new_dst1;
    dst[2] = new_dst2;
    dst[3] = new_dst3;

    prev_dst0 = new_dst0;
    prev_dst1 = new_dst1;
    prev_dst2 = new_dst2;
    prev_dst3 = new_dst3;

    dst += stride;
    src += stride;
}
}
