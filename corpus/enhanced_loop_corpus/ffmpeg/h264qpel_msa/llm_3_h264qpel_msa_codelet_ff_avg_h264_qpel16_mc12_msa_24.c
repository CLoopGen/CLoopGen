#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src_offset = src;
    uint8_t *dst_offset = dst;
    ptrdiff_t small_stride = stride / 4;

    for (row = 16; row--;) {
        dst_offset[0 * small_stride] = src_offset[0 * small_stride];
        dst_offset[1 * small_stride] = src_offset[1 * small_stride];
        dst_offset[2 * small_stride] = src_offset[2 * small_stride];
        dst_offset[3 * small_stride] = src_offset[3 * small_stride];

        src_offset += stride;
        dst_offset += stride;
    }

    src = src_offset - (16 * stride);
    dst = dst_offset - (16 * stride);
}
