#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t val_src[4], val_dst[4];
    int offset;

    // Introduce WAW and WAR dependencies via staged memory reads
    offset = 0;
    val_src[0] = src[offset];
    val_src[1] = src[offset + src_stride];
    val_src[2] = src[offset + 2*src_stride];
    val_src[3] = src[offset + 3*src_stride];

    // RAW dependency: use src values to compute dst
    val_dst[0] = val_src[0] + val_src[1];
    val_dst[1] = val_src[1] + val_src[2];
    val_dst[2] = val_src[2] + val_src[3];
    val_dst[3] = val_src[3] + val_src[0];

    // Write results with stride — introduces potential WAW if previous loop iteration not completed
    dst[0] = val_dst[0];
    dst[dst_stride] = val_dst[1];
    dst[2*dst_stride] = val_dst[2];
    dst[3*dst_stride] = val_dst[3];

    // Update source pointer — carried dependency on prior src update
    src += (4 * src_stride);

    // Second block with data reuse: create loop-carried dependency via static state
    static uint8_t carry = 0;
    val_src[0] = src[0] + carry;
    val_src[1] = src[src_stride] + val_src[0];
    val_src[2] = src[2*src_stride] + val_src[1];
    val_src[3] = src[3*src_stride] + val_src[2];

    // Feedback into carry creates loop-carried dependency
    carry = val_src[3];

    dst[0] = val_src[0];
    dst[dst_stride] = val_src[1];
    dst[2*dst_stride] = val_src[2];
    dst[3*dst_stride] = val_src[3];

    dst += (4 * dst_stride);
}
}
