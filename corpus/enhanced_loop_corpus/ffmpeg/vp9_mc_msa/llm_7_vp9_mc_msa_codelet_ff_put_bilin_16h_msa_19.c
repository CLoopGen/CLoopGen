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
    uint8_t accumulator = 0;

    for (; cnt--;) {
        accumulator ^= s[0];
        accumulator ^= s[s_stride];
        accumulator ^= s[2*s_stride];
        accumulator ^= s[3*s_stride];

        d[0] = accumulator;
        d[d_stride] = accumulator ^ 0x55;
        d[2*d_stride] = accumulator ^ 0xAA;
        d[3*d_stride] = accumulator ^ 0xFF;

        s += 4 * s_stride;

        d += 4 * d_stride;
    }

    dst = d;
    src = s;
}
