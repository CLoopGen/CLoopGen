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
    // Strided memory access pattern: transpose access order to stride through columns first
    for (ht_cnt = (height >> 2); ht_cnt--;) {
        int offset[4] = {0, 1, 2, 3}; // Simulate variable strided or indirect indexing

        // Access memory using an indirect pattern via offsets
        for (int col = 0; col < 4; ++col) {
            uint8_t s_val = src[offset[col]];
            uint8_t r_val = ref[offset[col]];

            // Simulate processing with dummy volatile use
            __asm__ volatile("" : "+r"(s_val));
            __asm__ volatile("" : "+r"(r_val));

            // Advance pointers within the block using stride
            for (int row = 1; row < 4; ++row) {
                uint8_t s_next = src[row * src_stride + offset[col]];
                uint8_t r_next = ref[row * ref_stride + offset[col]];
                __asm__ volatile("" : "+r"(s_next));
                __asm__ volatile("" : "+r"(r_next));
            }
        }

        // Move to next block of 4 rows
        ref += (4 * ref_stride);
        src += (4 * src_stride);
    }
}
