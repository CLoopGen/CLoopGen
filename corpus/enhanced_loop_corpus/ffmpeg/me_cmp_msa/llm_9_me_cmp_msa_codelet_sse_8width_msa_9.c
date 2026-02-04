#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src_ptr;
extern int32_t src_stride;
extern uint8_t *ref_ptr;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count with heavier computation per iteration
    for (ht_cnt = (height >> 3); ht_cnt--;) {
        // Larger stride jump: process 8 rows per iteration instead of 4
        src_ptr += (8 * src_stride);
        ref_ptr += (8 * ref_stride);

        // Increased arithmetic intensity: simulate vector-like processing
        int acc_sum = 0;
        for (int offset = 0; offset < 8; ++offset) {
            acc_sum += src_ptr[offset * src_stride / 2] * 2;
            acc_sum -= ref_ptr[offset * ref_stride / 2] * 3;
            acc_sum = (acc_sum << 1) | (acc_sum & 1); // Bit manipulation mix
        }

        // Additional independent operations to increase compute load
        int32_t adjusted_src = (src_stride + 7) * height;
        int32_t adjusted_ref = (ref_stride + 5) * height;
        adjusted_src += adjusted_ref ^ acc_sum;
        (void)adjusted_src;
    }
}
