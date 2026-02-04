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
    // Change to strided memory access with reversed and alternating pattern
    int strides[8] = {7, 5, 3, 1, 0, 2, 4, 6}; // Non-sequential stride indices
    for (int i = 0; i < 8; ++i) {
        int s_idx = strides[i];
        int r_idx = strides[7 - i]; // Reverse mapping for reference
        uint8_t s_val = *(src + s_idx * src_stride);
        uint8_t r_val = *(ref + r_idx * ref_stride);
        // Use values in a way that prevents dead code elimination
        *(src + s_idx * src_stride) = (s_val ^ r_val);
    }
    // Update base pointers after block processing
    src += (8 * src_stride);
    ref += (8 * ref_stride);
}
}
