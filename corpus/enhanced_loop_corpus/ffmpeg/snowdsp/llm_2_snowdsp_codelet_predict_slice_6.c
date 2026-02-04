#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *buf;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int ref_stride;
extern uint8_t *dst8;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling by factor of 2
    // Access pattern changed to process two elements per iteration for better spatial locality
    int start_y = block_h * mb_y;
    int end_y = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);

    for (y = start_y; y < end_y; y++) {
        IDWTELEM *row_buf = &buf[y * w];
        uint8_t *row_dst = &dst8[y * ref_stride];
        int x = 0;

        // Unroll by 2: process two pixels at a time
        for (; x <= w - 2; x += 2) {
            int v1 = row_buf[x]     + (128 << 4) + (1 << (4 - 1));
            int v2 = row_buf[x + 1] + (128 << 4) + (1 << (4 - 1));

            v1 >>= 4;
            v2 >>= 4;

            v1 = (v1 & (~255)) ? ~(v1 >> 31) : v1;
            v2 = (v2 & (~255)) ? ~(v2 >> 31) : v2;

            row_dst[x]     = (uint8_t)v1;
            row_dst[x + 1] = (uint8_t)v2;
        }

        // Handle remaining element if w is odd
        for (; x < w; x++) {
            int v = row_buf[x] + (128 << 4) + (1 << (4 - 1));
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);
            row_dst[x] = v;
        }
    }
}
