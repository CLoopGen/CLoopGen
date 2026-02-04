#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *s0, *s1;
    uint8_t *d0, *d1;
    uint32_t i;
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        s0 = src;
        s1 = src + src_stride;
        d0 = dst;
        d1 = dst + dst_stride;

        for (i = 0; i < 4; ++i) {
            d0[i] = s0[i] + 1;
            d1[i] = s1[i] + 1;
        }

        src += 2 * src_stride;
        dst += 2 * dst_stride;
    }
}
