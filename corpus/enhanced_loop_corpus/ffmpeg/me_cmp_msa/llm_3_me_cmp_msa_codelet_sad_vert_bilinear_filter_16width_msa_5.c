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
    // Variant 2: Strided and scattered memory access using indirect indexing
    // Instead of direct pointer arithmetic, use index arrays to simulate irregular,
    // strided, or out-of-order memory accesses common in optimized multimedia kernels.

    // Precomputed offset vectors to simulate non-consecutive access patterns
    int32_t src_offsets[] = {0, 4, 8, 12, 16, 20, 24, 28};
    int32_t ref_offsets[] = {0, 5, 10, 15, 20, 25, 30, 35};

    for (ht_cnt = (height >> 3); ht_cnt--;) {
        // Use indirect addressing via offsets to create a strided, non-unit access pattern
        uint8_t* src_base = src;
        uint8_t* ref_base = ref;

        // Simulate block-wise access with gaps (strided fetches)
        for (int i = 0; i < 8; i += 2) {
            volatile uint8_t s1 = src_base[src_offsets[i]];
            volatile uint8_t r1 = ref_base[ref_offsets[i]];
            volatile uint8_t s2 = src_base[src_offsets[i+1]];
            volatile uint8_t r2 = ref_base[ref_offsets[i+1]];

            // Prevent compiler optimization from eliminating reads
            (void)s1; (void)r1; (void)s2; (void)r2;
        }

        // Update base pointers with large strides to skip processed blocks
        src += (8 * src_stride);
        ref += (8 * ref_stride);
    }
}
