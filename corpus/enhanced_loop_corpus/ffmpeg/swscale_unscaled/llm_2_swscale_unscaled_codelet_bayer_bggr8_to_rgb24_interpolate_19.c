#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern with local accumulation
    uint8_t *src0, *src1, *src2;
    uint8_t *dst_row0 = dst;
    uint8_t *dst_row1 = dst + dst_stride;

    for (i = 2; i < width - 2; i += 2) {
        src0 = src + (-1) * src_stride;
        src1 = src;
        src2 = src + src_stride;

        // Reuse loaded values in temporaries to enable consecutive writes
        uint8_t a = src0[1], b = src0[-1], c = src1[-1], d = src1[1], e = src2[-1], f = src2[1];
        uint8_t center = src1[0];
        uint8_t right = src1[2], down_center = src2[0], down_right = src2[2];

        // Compute and store row 0 of 2x3 block consecutively
        dst_row0[0] = (b + a + e + f) >> 2;
        dst_row0[1] = (src0[0] + c + d + down_center) >> 2;
        dst_row0[2] = center;

        // Row 1 of 2x3 block
        dst_row0[3] = (a + f) >> 1;
        dst_row0[4] = d;
        dst_row0[5] = (center + right) >> 1;

        dst_row1[0] = (e + f) >> 1;
        dst_row1[1] = down_center;
        dst_row1[2] = (center + down_right) >> 1;

        dst_row1[3] = src2[1];
        dst_row1[4] = (d + down_center + src2[2] + src[src_stride*2 + 1]) >> 2;
        dst_row1[5] = (center + right + src[src_stride*2 + 0] + src[src_stride*2 + 2]) >> 2;

        src += 2;
        dst_row0 += 6;
        dst_row1 += 6;
    }
}
