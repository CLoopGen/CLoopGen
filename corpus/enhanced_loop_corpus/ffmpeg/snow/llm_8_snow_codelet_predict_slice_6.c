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
    int y_end = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);
    for (y = y_start; y < y_end; y++) {
        IDWTELEM *buf_row = &buf[y * w];
        uint8_t *dst_row = &dst8[y * ref_stride];
        for (x = 0; x < w; x += 4) {
            int v0 = buf_row[x + 0] + (128 << 4) + (1 << 3);
            int v1 = buf_row[x + 1] + (128 << 4) + (1 << 3);
            int v2 = buf_row[x + 2] + (128 << 4) + (1 << 3);
            int v3 = buf_row[x + 3] + (128 << 4) + (1 << 3);

            v0 >>= 4;
            v1 >>= 4;
            v2 >>= 4;
            v3 >>= 4;

            v0 = (v0 & (~255)) ? ~(v0 >> 31) : v0;
            v1 = (v1 & (~255)) ? ~(v1 >> 31) : v1;
            v2 = (v2 & (~255)) ? ~(v2 >> 31) : v2;
            v3 = (v3 & (~255)) ? ~(v3 >> 31) : v3;

            dst_row[x + 0] = v0;
            dst_row[x + 1] = v1;
            dst_row[x + 2] = v2;
            dst_row[x + 3] = v3;
        }
        for (; x < w; x++) {
            int v = buf[x + y * w] + (128 << 4) + (1 << 3);
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8[x + y * ref_stride] = v;
        }
    }
}
