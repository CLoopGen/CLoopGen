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
        const uint8_t *s1_ptr = s1 + x;
        const uint8_t *s2_ptr = s2 + x;
        uint32_t *dst_ptr = dst + x;
        uint32_t *dst_top_ptr = dst_top + x;

        const int d0 = s1_ptr[0] - s2_ptr[0];
        const int d1 = s1_ptr[1] - s2_ptr[1];
        const int d2 = s1_ptr[2] - s2_ptr[2];
        const int d3 = s1_ptr[3] - s2_ptr[3];

        dst_ptr[0] = dst_top_ptr[0] - dst_top_ptr[-1] + d0 * d0;
        dst_ptr[1] = dst_top_ptr[1] - dst_top_ptr[0] + d1 * d1;
        dst_ptr[2] = dst_top_ptr[2] - dst_top_ptr[1] + d2 * d2;
        dst_ptr[3] = dst_top_ptr[3] - dst_top_ptr[2] + d3 * d3;

        dst_ptr[0] += dst_ptr[-1];
        dst_ptr[1] += dst_ptr[0];
        dst_ptr[2] += dst_ptr[1];
        dst_ptr[3] += dst_ptr[2];
    }
    s1 += linesize1;
    s2 += linesize2;
    dst += dst_linesize_32;
    dst_top += dst_linesize_32;
}
}
