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
    // Variant 1: Consecutive memory access with pointer arithmetic and loop unrolling by 2
    IDWTELEM *buf_base = buf + (block_h * mb_y) * w;
    uint8_t *dst_line = dst8 + (block_h * mb_y) * ref_stride;
    int end_y = (h > block_h * (mb_y + 1)) ? block_h * (mb_y + 1) : h;
    int y_offset = 0;

    for (int j = block_h * mb_y; j < end_y; j++) {
        IDWTELEM *buf_row = buf_base + y_offset * w;
        uint8_t *dst_row = dst_line + y_offset * ref_stride;

        // Unroll by 2 for consecutive access optimization
        int x = 0;
        for (; x + 1 < w; x += 2) {
            int v0 = buf_row[x] + (128 << 4) + (1 << (4 - 1));
            int v1 = buf_row[x+1] + (128 << 4) + (1 << (4 - 1));
            v0 >>= 4;
            v1 >>= 4;

            if (v0 & (~255)) v0 = ~(v0 >> 31);
            if (v1 & (~255)) v1 = ~(v1 >> 31);

            dst_row[x] = v0;
            dst_row[x+1] = v1;
        }
        // Handle remaining element if w is odd
        if (x < w) {
            int v = buf_row[x] + (128 << 4) + (1 << (4 - 1));
            v >>= 4;
            if (v & (~255)) v = ~(v >> 31);
            dst_row[x] = v;
        }
        y_offset++;
    }
}
