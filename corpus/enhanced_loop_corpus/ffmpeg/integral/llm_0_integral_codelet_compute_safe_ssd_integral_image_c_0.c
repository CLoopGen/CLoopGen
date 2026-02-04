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
for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x += 4) {
        const int d0 = s1[x] - s2[x];
        dst[x] = dst_top[x] - dst_top[x - 1] + d0 * d0;
        dst[x] += (x > 0) ? dst[x - 1] : 0;

        if (x + 1 < w) {
            const int d1 = s1[x + 1] - s2[x + 1];
            dst[x + 1] = dst_top[x + 1] - dst_top[x] + d1 * d1;
            dst[x + 1] += dst[x];
        }

        if (x + 2 < w) {
            const int d2 = s1[x + 2] - s2[x + 2];
            dst[x + 2] = dst_top[x + 2] - dst_top[x + 1] + d2 * d2;
            dst[x + 2] += dst[x + 1];
        }

        if (x + 3 < w) {
            const int d3 = s1[x + 3] - s2[x + 3];
            dst[x + 3] = dst_top[x + 3] - dst_top[x + 2] + d3 * d3;
            dst[x + 3] += dst[x + 2];
        }
    }
    s1 += linesize1;
    s2 += linesize2;
    dst += dst_linesize_32;
    dst_top += dst_linesize_32;
}
}
