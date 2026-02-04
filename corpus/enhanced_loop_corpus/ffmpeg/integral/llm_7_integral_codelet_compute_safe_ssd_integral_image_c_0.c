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
for (y = 0; y < h; y++) {
    uint32_t prev_accum = dst[y * dst_linesize_32 / sizeof(uint32_t) - 1]; // Simulate previous row's end value
    for (x = 0; x < w; x += 4) {
        const int d0 = s1[x] - s2[x];
        const int d1 = s1[x + 1] - s2[x + 1];
        const int d2 = s1[x + 2] - s2[x + 2];
        const int d3 = s1[x + 3] - s2[x + 3];
        uint32_t sq0 = d0 * d0;
        uint32_t sq1 = d1 * d1;
        uint32_t sq2 = d2 * d2;
        uint32_t sq3 = d3 * d3;
        uint32_t diff_top0 = dst_top[x] - (x == 0 ? prev_accum : dst_top[x - 1]);
        dst[x] = diff_top0 + sq0;
        if (x > 0 || y > 0) {
            dst[x] += (x == 0 ? dst[(y-1) * dst_linesize_32/sizeof(uint32_t) + w/4*4 - 1] : dst[x - 1]);
        }
        dst[x + 1] = (dst_top[x + 1] - dst_top[x]) + sq1 + dst[x];
        dst[x + 2] = (dst_top[x + 2] - dst_top[x + 1]) + sq2 + dst[x + 1];
        dst[x + 3] = (dst_top[x + 3] - dst_top[x + 2]) + sq3 + dst[x + 2];
    }
    s1 += linesize1;
    s2 += linesize2;
    dst += dst_linesize_32;
    dst_top += dst_linesize_32;
}
}
