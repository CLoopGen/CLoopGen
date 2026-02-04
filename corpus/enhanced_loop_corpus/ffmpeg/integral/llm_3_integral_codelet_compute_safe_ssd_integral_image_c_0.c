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
    uint8_t *s1_row = s1;
    uint8_t *s2_row = s2;
    uint32_t *dst_row = dst;
    uint32_t *dst_top_row = dst_top;

    for (x = 0; x < w; x += 4) {
        const ptrdiff_t idx = x;

        const int d0 = *(s1_row + idx) - *(s2_row + idx);
        const int d1 = *(s1_row + idx + 1) - *(s2_row + idx + 1);
        const int d2 = *(s1_row + idx + 2) - *(s2_row + idx + 2);
        const int d3 = *(s1_row + idx + 3) - *(s2_row + idx + 3);

        uint32_t val0 = *(dst_top_row + idx) - *(dst_top_row + idx - 1) + d0 * d0;
        uint32_t val1 = *(dst_top_row + idx + 1) - *(dst_top_row + idx) + d1 * d1;
        uint32_t val2 = *(dst_top_row + idx + 2) - *(dst_top_row + idx + 1) + d2 * d2;
        uint32_t val3 = *(dst_top_row + idx + 3) - *(dst_top_row + idx + 2) + d3 * d3;

        val0 += *(dst_row + idx - 1);
        val1 += val0;
        val2 += val1;
        val3 += val2;

        *(dst_row + idx)     = val0;
        *(dst_row + idx + 1) = val1;
        *(dst_row + idx + 2) = val2;
        *(dst_row + idx + 3) = val3;
    }

    s1 += linesize1;
    s2 += linesize2;
    dst += dst_linesize_32;
    dst_top += dst_linesize_32;
}
}
