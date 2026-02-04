#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *ref;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed and interleaved row traversal
    for (ht_cnt = (height >> 3); ht_cnt--;) {
        int32_t stride_step = 2 * src_stride;
        int32_t ref_step = 2 * ref_stride;

        // Access rows in reverse order and process two at a time with larger stride
        uint8_t *src_top = src + 6 * src_stride;
        uint8_t *src_bot = src + 7 * src_stride;
        uint8_t *ref_top = ref + 6 * ref_stride;
        uint8_t *ref_bot = ref + 7 * ref_stride;

        // Interleaved processing pattern: bottom-up, strided access
        { }
        { }
        src_bot += stride_step;
        ref_bot += ref_step;

        { }
        { }
        src_top -= stride_step;
        ref_top -= ref_step;

        { }
        { }
        src_bot += stride_step;
        ref_bot += ref_step;

        { }
        { }
        src_top -= stride_step;
        ref_top -= ref_step;

        // Advance to next block of 8 rows
        src += (8 * src_stride);
        ref += (8 * ref_stride);

        { }
        { }
        { }
        { }
    }
}
