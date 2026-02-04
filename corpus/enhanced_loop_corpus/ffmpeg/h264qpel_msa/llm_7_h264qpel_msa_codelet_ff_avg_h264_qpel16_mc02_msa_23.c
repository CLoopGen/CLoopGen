#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 4; loop_cnt--;) {
    uint8_t *local_src = src + (4 * stride);
    uint8_t *local_dst = dst + (4 * stride);

    dst[0] = src[0];
    dst[stride] = src[stride];
    dst[2*stride] = src[2*stride];
    dst[3*stride] = src[3*stride];

    src = local_src;
    dst = local_dst;
}
}
