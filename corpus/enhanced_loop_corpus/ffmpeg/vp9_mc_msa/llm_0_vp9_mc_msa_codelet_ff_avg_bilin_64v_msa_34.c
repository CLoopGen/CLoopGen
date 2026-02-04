#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint32_t outer = 0; outer < (height >> 2); ++outer) {
        for (uint32_t inner = 0; inner < 2; ++inner) {
            src += (2 * src_stride);
            dst += (2 * dst_stride);
        }
    }
}
