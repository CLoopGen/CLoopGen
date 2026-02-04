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
for (loop_count = (height >> 2); loop_count--;) {
    uint8_t val;
    int32_t offset;

    offset = 0;
    val = src[offset + 0 * src_stride];
    dst[offset] = val;

    offset = dst_stride;
    val = src[offset + 0 * src_stride]; // RAW dependency on offset
    dst[offset] = val;

    offset = 2 * dst_stride;
    val = src[offset - dst_stride]; // WAR-like pattern via artificial reuse of 'val'
    dst[offset] = val;

    offset = 3 * dst_stride;
    val = src[offset - 2 * dst_stride]; // Introduces WAW on 'val', breaks direct indexing pattern
    dst[offset] = val;

    // Loop-carried dependency: current dst update affects next src base indirectly via side effect
    // (though not data-flow dependent, memory access pattern is preserved)
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
