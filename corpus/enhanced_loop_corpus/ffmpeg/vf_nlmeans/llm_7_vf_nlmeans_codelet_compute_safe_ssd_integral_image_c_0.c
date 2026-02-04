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
    uint32_t carry = 0;
    for (x = 0; x < w; x += 4) {
        const int d0 = s1[x] - s2[x];
        const int d1 = s1[x + 1] - s2[x + 1];
        const int d2 = s1[x + 2] - s2[x + 2];
        const int d3 = s1[x + 3] - s2[x + 3];

        uint32_t val0 = dst_top[x] - (x == 0 ? 0 : dst_top[x - 1]) + d0 * d0;
        uint32_t val1 = dst_top[x + 1] - dst_top[x] + d1 * d1;
        uint32_t val2 = dst_top[x + 2] - dst_top[x + 1] + d2 * d2;
        uint32_t val3 = dst_top[x + 3] - dst_top[x + 2] + d3 * d3;

        val0 += carry;
        carry = val0;
        val1 += carry;
        carry = val1;
        val2 += carry;
        carry = val2;
        val3 += carry;
        carry = val3;

        dst[x] = val0;
        dst[x + 1] = val1;
        dst[x + 2] = val2;
        dst[x + 3] = val3;
    }
    s1 += linesize1;
    s2 += linesize2;
    dst += dst_linesize_32;
    dst_top += dst_linesize_32;
}
}
