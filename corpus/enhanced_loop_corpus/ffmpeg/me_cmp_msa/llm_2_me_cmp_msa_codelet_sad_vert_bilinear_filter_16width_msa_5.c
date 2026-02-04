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
    for (ht_cnt = (height >> 3); ht_cnt--;) {
        // Variant 1: Consecutive memory access with linear prefetching pattern
        // Access src and ref in a sequential, cache-friendly manner by reducing stride jumps
        // and simulating wider vector-like loads via incremental pointer updates.

        src += src_stride;
        ref += ref_stride;

        // Simulate processing of multiple adjacent rows with smaller effective strides
        for (int i = 0; i < 4; ++i) {
            src += src_stride;
            ref += ref_stride;
        }

        // Mid-loop adjustment with non-power-of-two stride to simulate irregular but predictable access
        src += (2 * src_stride);
        ref += (4 * ref_stride);

        for (int i = 0; i < 4; ++i) {
            src += src_stride;
            ref += ref_stride;
        }

        src += (2 * src_stride);
        ref += (4 * ref_stride);
    }
}
