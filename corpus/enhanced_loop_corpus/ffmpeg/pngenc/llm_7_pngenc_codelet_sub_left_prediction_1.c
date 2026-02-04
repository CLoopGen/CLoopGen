#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int x;
extern int unaligned_w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint8_t *local_src1 = src1;
    uint8_t *local_src2 = src2;
    for (x = 0; x < unaligned_w; x += 4) {
        local_dst[0] = local_src1[0] - local_src2[0];
        local_dst[1] = local_src1[1] - local_src2[1];
        local_dst[2] = local_src1[2] - local_src2[2];
        local_dst[3] = local_src1[3] - local_src2[3];
        local_dst += 4;
        local_src1 += 4;
        local_src2 += 4;
    }
    dst = local_dst;
    src1 = local_src1;
    src2 = local_src2;
}
