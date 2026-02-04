#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint32_t offset = 0;
for (loop_cnt = (height >> 2); loop_cnt--;) {
    // Introduce WAW and WAR dependencies via staged writes with temporary accumulators
    uint32_t accum = 0;
    accum += src[offset + 0 * src_stride];
    accum += src[offset + 1 * src_stride];
    accum += src[offset + 2 * src_stride];
    accum += src[offset + 3 * src_stride];

    // Loop-carried dependency: accum from previous iteration affects current write
    static uint8_t running_avg = 128;
    running_avg = (running_avg + (accum >> 2)) >> 1;

    dst[0 * dst_stride] = running_avg;
    dst[1 * dst_stride] = running_avg ^ 0xFF;
    dst[2 * dst_stride] = running_avg;
    dst[3 * dst_stride] = running_avg ^ 0xAA;

    offset += 4 * src_stride;
    dst += 4 * dst_stride;
}
}
