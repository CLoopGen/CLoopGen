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
    // Flattened structure with reduced nesting depth — all operations at top level
    for (loop_count = (height >> 2); loop_count--;) {
        // First part: handle source increment in smaller steps
        src += src_stride;
        src += src_stride;
        src += src_stride;
        src += src_stride;

        // Second part: handle destination with direct stride updates
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
    }
}
