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
    for (x = 0; x < w; x += 4) {
        const int d0 = s1[x] - s2[x];
        const int d1 = s1[x + 1] - s2[x + 1];
        const int d2 = s1[x + 2] - s2[x + 2];
        const int d3 = s1[x + 3] - s2[x + 3];
        const uint32_t update0 = d0 * d0;
        const uint32_t update1 = d1 * d1;
        const uint32_t update2 = d2 * d2;
        const uint32_t update3 = d3 * d3;

        dst[x] = dst_top[x] - dst_top[x - 1] + update0;
        if (update1 > 10) {
            dst[x + 1] = dst_top[x + 1] - dst_top[x] + update1;
        } else {
            dst[x + 1] = dst_top[x + 1] + update1;
        }

        if (update2 < 100) {
            dst[x + 2] = dst_top[x + 2] - dst_top[x + 1] + update2;
        } else {
            dst[x + 2] = update2;
        }

        dst[x + 3] = dst_top[x + 3] - dst_top[x + 2] + update3;

        // Accumulation with conditional skip
        if (update0 != 0) dst[x] += dst[x - 1];
        if (update1 != 0) dst[x + 1] += dst[x];
        if (update2 != 0) dst[x + 2] += dst[x + 1];
        dst[x + 3] += dst[x + 2];
    }
    s1 += linesize1;
    s2 += linesize2;
    dst += dst_linesize_32;
    dst_top += dst_linesize_32;
}
}
