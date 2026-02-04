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
    int y_start = block_h * mb_y;
    int y_end = (h > block_h * (mb_y + 1)) ? block_h * (mb_y + 1) : h;
    for (y = y_start; y < y_end; y++) {
        int offset = y * w;
        int dst_offset = y * ref_stride;
        x = 0;
        for (; x < w; x += 2) {
            int v1 = buf[x + offset] + (128 << 4) + (1 << (4 - 1));
            v1 >>= 4;
            if (v1 & (~255))
                v1 = ~(v1 >> 31);
            dst8[x + dst_offset] = v1;

            if (x + 1 < w) {
                int v2 = buf[x + 1 + offset] + (128 << 4) + (1 << (4 - 1));
                v2 >>= 4;
                if (v2 & (~255))
                    v2 = ~(v2 >> 31);
                dst8[x + 1 + dst_offset] = v2;
            }
        }
        while (x < w) {
            int v = buf[x + offset] + (128 << 4) + (1 << (4 - 1));
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8[x + dst_offset] = v;
            x++;
        }
    }
}
