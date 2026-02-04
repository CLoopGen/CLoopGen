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
    // Reduced computational intensity with increased trip count and simplified operations
    for (loop_count = height; loop_count--;) {
        // Simplified byte-wise copy with minimal arithmetic
        *dst = *src;

        // Update pointers once per iteration instead of batching
        src += src_stride;
        dst += dst_stride;
    }
}
