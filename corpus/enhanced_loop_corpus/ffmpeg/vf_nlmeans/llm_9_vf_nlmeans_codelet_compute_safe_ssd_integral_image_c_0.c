#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *dst;
extern ptrdiff_t dst_linesize_32;
extern  uint8_t *s1;
extern ptrdiff_t linesize1;
extern  uint8_t *s2;
extern ptrdiff_t linesize2;
extern int w;
extern int h;
extern int x;
extern int y;
extern  uint32_t *dst_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x += 4) {
        const int d0 = s1[x] - s2[x];
        const int d1 = s1[x + 1] - s2[x + 1];
        const int d2 = s1[x + 2] - s2[x + 2];
        const int d3 = s1[x + 3] - s2[x + 3];
        uint32_t temp0 = d0 * d0;
        uint32_t temp1 = d1 * d1;
        uint32_t temp2 = d2 * d2;
        uint32_t temp3 = d3 * d3;
        dst[x] = dst_top[x] - ((x > 0) ? dst_top[x - 1] : 0) + temp0;
        dst[x + 1] = dst_top[x + 1] - dst_top[x] + temp1;
        dst[x + 2] = dst_top[x + 2] - dst_top[x + 1] + temp2;
        dst[x + 3] = dst_top[x + 3] - dst_top[x + 2] + temp3;
        dst[x] += (x > 0) ? dst[x - 1] : 0;
        dst[x + 1] += dst[x];
        dst[x + 2] += dst[x + 1];
        dst[x + 3] += dst[x + 2];

        if (y + 1 < h) {
            const uint8_t *s1_next = s1 + linesize1;
            const uint8_t *s2_next = s2 + linesize2;
            const uint32_t *top_next = dst_top + dst_linesize_32;
            const int d0n = s1_next[x] - s2_next[x];
            const int d1n = s1_next[x + 1] - s2_next[x + 1];
            const int d2n = s1_next[x + 2] - s2_next[x + 2];
            const int d3n = s1_next[x + 3] - s2_next[x + 3];
            uint32_t t0 = d0n * d0n;
            uint32_t t1 = d1n * d1n;
            uint32_t t2 = d2n * d2n;
            uint32_t t3 = d3n * d3n;
            uint32_t *dst_row_next = dst + dst_linesize_32;
            dst_row_next[x] = top_next[x] - ((x > 0) ? top_next[x - 1] : 0) + t0;
            dst_row_next[x + 1] = top_next[x + 1] - top_next[x] + t1;
            dst_row_next[x + 2] = top_next[x + 2] - top_next[x + 1] + t2;
            dst_row_next[x + 3] = top_next[x + 3] - top_next[x + 2] + t3;
            dst_row_next[x] += (x > 0) ? dst_row_next[x - 1] : 0;
            dst_row_next[x + 1] += dst_row_next[x];
            dst_row_next[x + 2] += dst_row_next[x + 1];
            dst_row_next[x + 3] += dst_row_next[x + 2];
        }
    }
    s1 += 2 * linesize1;
    s2 += 2 * linesize2;
    dst += 2 * dst_linesize_32;
    dst_top += 2 * dst_linesize_32;
}
}
