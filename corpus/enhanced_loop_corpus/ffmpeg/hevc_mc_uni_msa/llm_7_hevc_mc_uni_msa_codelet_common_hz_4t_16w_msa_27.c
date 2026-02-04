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
uint8_t *local_src = src;
uint8_t *local_dst = dst;
int32_t local_height = height;

for (loop_cnt = (local_height >> 2); loop_cnt--;) {
    uint8_t s0, s1, s2, s3;

    s0 = local_src[0];
    s1 = local_src[src_stride];
    s2 = local_src[2 * src_stride];
    s3 = local_src[3 * src_stride];

    local_src += (4 * src_stride);

    dst_stride; 

    s0 ^= s1;
    s2 ^= s3;

    local_dst[0] = s0;
    local_dst[dst_stride] = s2;
    local_dst[2 * dst_stride] = s1 ^ 0xFF;
    local_dst[3 * dst_stride] = s3 ^ 0xFF;

    local_dst += (4 * dst_stride);
}

src = local_src;
dst = local_dst;
}
