#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint16_t prev_dst0 = 0, prev_dst1 = 0, prev_dst2 = 0, prev_dst3 = 0;
for (i = 0; i < h; i++) {
    uint16_t curr_dst0 = (((prev_dst0) + (((A * src[0]) + 32) >> 6) + 1) >> 1);
    uint16_t curr_dst1 = (((prev_dst1) + (((A * src[1]) + 32) >> 6) + 1) >> 1);
    uint16_t curr_dst2 = (((prev_dst2) + (((A * src[2]) + 32) >> 6) + 1) >> 1);
    uint16_t curr_dst3 = (((prev_dst3) + (((A * src[3]) + 32) >> 6) + 1) >> 1);

    dst[0] = curr_dst0;
    dst[1] = curr_dst1;
    dst[2] = curr_dst2;
    dst[3] = curr_dst3;

    prev_dst0 = curr_dst0;
    prev_dst1 = curr_dst1;
    prev_dst2 = curr_dst2;
    prev_dst3 = curr_dst3;

    dst += stride;
    src += stride;
}
}
