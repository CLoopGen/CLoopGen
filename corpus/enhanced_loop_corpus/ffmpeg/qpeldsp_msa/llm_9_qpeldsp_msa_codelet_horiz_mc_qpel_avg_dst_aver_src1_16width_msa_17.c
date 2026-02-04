#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_count = (height >> 2); loop_count > 0; loop_count -= 2) {
    int offset_src, offset_dst;
    for (int step = 0; step < 2 && loop_count > 0; ++step, --loop_count) {
        offset_src = 4 * src_stride;
        offset_dst = 2 * dst_stride;

        dst[0] = src[0];
        dst[1 * dst_stride] = src[1 * src_stride];
        dst[2 * dst_stride] = src[2 * src_stride];
        dst[3 * dst_stride] = src[3 * src_stride];

        src += offset_src;
        dst += offset_dst;
    }
    if (loop_count <= 0) break;
    dst += (4 * dst_stride);
}
}
