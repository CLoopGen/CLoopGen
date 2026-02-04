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
for (loop_cnt = height >> 2; loop_cnt--;) {
    // Change to strided memory access: process one row at a time but with stride jumps
    for (int32_t s = 0; s < 4; ++s) {
        uint8_t *src_row = src + s * src_stride;
        uint8_t *dst_row = dst + s * dst_stride;

        // Perform vertical accumulation or patterned write (example: duplicate pixel every 2nd byte)
        for (int32_t col = 0; col < 4; ++col) {
            dst_row[col * 2 + 0] = src_row[col];
            dst_row[col * 2 + 1] = src_row[col]; // duplicated
        }
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
