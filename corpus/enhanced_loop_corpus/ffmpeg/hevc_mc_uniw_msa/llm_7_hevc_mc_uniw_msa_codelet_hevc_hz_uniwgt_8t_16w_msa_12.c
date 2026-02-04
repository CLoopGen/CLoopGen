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
for (loop_cnt = (height >> 1); loop_cnt--;) {
    uint8_t val_top_src, val_bottom_src;
    uint32_t acc = 0;

    // Introduce WAW and WAR dependencies via accumulator
    val_top_src = src[0];
    acc += val_top_src;
    val_bottom_src = src[src_stride];
    acc += val_bottom_src;
    
    // Write to destination with combined value — creates loop-carried dependency on 'acc'
    dst[0] = (uint8_t)(acc & 0xFF);
    dst[dst_stride] = (uint8_t)((acc >> 8) & 0xFF);

    // Artificially create a loop-carried dependency using static variable
    static uint8_t carry_over = 0;
    dst[1] = carry_over;
    carry_over = dst[0];

    // Update pointers
    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
