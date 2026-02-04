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
    // Variant 1: Consecutive memory access with loop unrolling by 2
    // This variant restructures the inner loop to access buf and dst8 in a more cache-friendly, consecutive manner
    // by processing two elements per iteration to increase spatial locality.
    int start_y = block_h * mb_y;
    int end_y = (h > block_h * (mb_y + 1)) ? block_h * (mb_y + 1) : h;

    for (y = start_y; y < end_y; y++) {
        IDWTELEM* buf_row = &buf[y * w];
        uint8_t* dst_row = &dst8[y * ref_stride];
        int x = 0;

        // Process two elements at a time
        for (; x <= w - 2; x += 2) {
            int v1 = buf_row[x] + (128 << 4) + (1 << (4 - 1));
            int v2 = buf_row[x + 1] + (128 << 4) + (1 << (4 - 1));

            v1 >>= 4;
            v2 >>= 4;

            if (v1 & (~255))
                v1 = ~(v1 >> 31);
            if (v2 & (~255))
                v2 = ~(v2 >> 31);

            dst_row[x] = v1;
            dst_row[x + 1] = v2;
        }

        // Handle remaining element if w is odd
        for (; x < w; x++) {
            int v = buf_row[x] + (128 << 4) + (1 << (4 - 1));
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst_row[x] = v;
        }
    }
}
