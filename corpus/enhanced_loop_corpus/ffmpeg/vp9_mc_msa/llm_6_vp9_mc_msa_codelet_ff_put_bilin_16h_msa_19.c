#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t cnt = loop_cnt;
    uint8_t *d = dst;
    uint8_t *s = src;
    ptrdiff_t d_stride = dst_stride;
    ptrdiff_t s_stride = src_stride;

    for (; cnt--;) {
        uint8_t temp1 = s[0];
        uint8_t temp2 = s[s_stride];
        uint8_t temp3 = s[2*s_stride];
        uint8_t temp4 = s[3*s_stride];

        d[0] = temp1 + 1;
        d[d_stride] = temp2 + 2;
        d[2*d_stride] = temp3 + 3;
        d[3*d_stride] = temp4 + 4;

        s += 4 * s_stride;
        d += 4 * d_stride;
    }

    dst = d;
    src = s;
}
