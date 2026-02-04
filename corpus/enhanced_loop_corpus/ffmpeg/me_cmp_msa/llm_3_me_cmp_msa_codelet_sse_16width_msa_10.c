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
    // Change memory access pattern to indirect indexing using array-of-pointers style simulation
    // Precompute row addresses using offsets, then access in a batched manner
    int32_t total_stride = src_stride * 4;
    for (ht_cnt = (height >> 2); ht_cnt--;) {
        // Create an array of base offsets for strided access over four rows
        ptrdiff_t src_offsets[4], ref_offsets[4];
        for (int i = 0; i < 4; ++i) {
            src_offsets[i] = i * src_stride;
            ref_offsets[i] = i * ref_stride;
        }

        // Use indirect access via computed offsets
        for (int i = 0; i < 4; ++i) {
            uint8_t *s = src_ptr + src_offsets[i];
            uint8_t *r = ref_ptr + ref_offsets[i];
            {
                {
                }
                ;
                {
                }
                ;
                {
                }
                ;
            }
        }

        // Advance pointers by four rows
        src_ptr += total_stride;
        ref_ptr += total_stride;
    }
}
