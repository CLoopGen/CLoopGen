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
        dst[x] = dst_top[x] - (y > 0 ? dst_top[x - 1] : 0) + temp0;
        dst[x + 1] = dst_top[x + 1] - dst_top[x] + temp1;
        dst[x + 2] = dst_top[x + 2] - dst_top[x + 1] + temp2;
        dst[x + 3] = dst_top[x + 3] - dst_top[x + 2] + temp3;
        dst[x] += (x > 0 ? dst[x - 1] : 0);
        dst[x + 1] += dst[x];
        dst[x + 2] += dst[x + 1];
        dst[x + 3] += dst[x + 2];
        if (y + 1 < h) {
            const int d0b = s1[x + linesize1] - s2[x + linesize1];
            const int d1b = s1[x + 1 + linesize1] - s2[x + 1 + linesize1];
            const int d2b = s1[x + 2 + linesize1] - s2[x + 2 + linesize1];
            const int d3b = s1[x + 3 + linesize1] - s2[x + 3 + linesize1];
            dst[x] = dst_top[x] - dst_top[x - 1] + d0b * d0b;
            dst[x + 1] = dst_top[x + 1] - dst_top[x] + d1b * d1b;
            dst[x + 2] = dst_top[x + 2] - dst_top[x + 1] + d2b * d2b;
            dst[x + 3] = dst_top[x + 3] - dst_top[x + 2] + d3b * d3b;
            dst[x] += dst[x - 1];
            dst[x + 1] += dst[x];
            dst[x + 2] += dst[x + 1];
            dst[x + 3] += dst[x + 2];
        }
    }
    s1 += 2 * linesize1;
    s2 += 2 * linesize2;
    dst += 2 * dst_linesize_32;
    dst_top += 2 * dst_linesize_32;
}
}
