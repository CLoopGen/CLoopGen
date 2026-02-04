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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t *s0 = src;
    uint8_t *s1 = src + src_stride;
    uint8_t *s2 = src + 2 * src_stride;
    uint8_t *s3 = src + 3 * src_stride;
    uint8_t *d0 = dst;
    uint8_t *d1 = dst + dst_stride;
    uint8_t *d2 = dst + 2 * dst_stride;
    uint8_t *d3 = dst + 3 * dst_stride;

    d0[0] = s0[0];
    d1[0] = s1[0];
    d2[0] = s2[0];
    d3[0] = s3[0];

    s0 += 4 * src_stride;
    s1 += 4 * src_stride;
    s2 += 4 * src_stride;
    s3 += 4 * src_stride;

    d0 += 4 * dst_stride;
    d1 += 4 * dst_stride;
    d2 += 4 * dst_stride;
    d3 += 4 * dst_stride;

    d0[-4 * dst_stride] ^= d1[-4 * dst_stride];
    d1[-3 * dst_stride] ^= d2[-3 * dst_stride];
    d2[-2 * dst_stride] ^= d3[-2 * dst_stride];
    d3[-1 * dst_stride] ^= d0[-1 * dst_stride];

    src = s0 - 4 * src_stride;
    dst = d0 - 4 * dst_stride;

    src += 4 * src_stride;
    dst += 4 * dst_stride;
}
}
