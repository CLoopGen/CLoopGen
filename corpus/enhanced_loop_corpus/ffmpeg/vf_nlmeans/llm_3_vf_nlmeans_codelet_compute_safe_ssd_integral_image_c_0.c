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
    uint8_t *s1_ptr = s1;
    uint8_t *s2_ptr = s2;
    uint32_t *dst_ptr = dst;
    uint32_t *dst_top_ptr = dst_top;
    for (x = 0; x < w; x += 4) {
        const int d[4] = {
            s1_ptr[0] - s2_ptr[0],
            s1_ptr[1] - s2_ptr[1],
            s1_ptr[2] - s2_ptr[2],
            s1_ptr[3] - s2_ptr[3]
        };
        dst_ptr[0] = dst_top_ptr[0] - dst_top_ptr[-1] + d[0] * d[0];
        dst_ptr[1] = dst_top_ptr[1] - dst_top_ptr[0] + d[1] * d[1];
        dst_ptr[2] = dst_top_ptr[2] - dst_top_ptr[1] + d[2] * d[2];
        dst_ptr[3] = dst_top_ptr[3] - dst_top_ptr[2] + d[3] * d[3];
        dst_ptr[0] += dst_ptr[-1];
        dst_ptr[1] += dst_ptr[0];
        dst_ptr[2] += dst_ptr[1];
        dst_ptr[3] += dst_ptr[2];
        s1_ptr += 4;
        s2_ptr += 4;
        dst_ptr += 4;
        dst_top_ptr += 4;
    }
    s1 += linesize1;
    s2 += linesize2;
    dst += dst_linesize_32;
    dst_top += dst_linesize_32;
}
}
