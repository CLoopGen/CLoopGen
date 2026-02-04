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
// Indirect memory access via index array to simulate irregular access pattern
int32_t indices[4] = {0, 1, 2, 3}; // Simulate flexible indexing (e.g., for reordering or subsampling)

for (ht_cnt = (height >> 2); ht_cnt--;) {
    uint8_t temp_sum_src = 0, temp_sum_ref = 0;

    // Strided but accessed indirectly using indices
    for (int i = 0; i < 4; ++i) {
        int32_t idx = indices[i] * src_stride;
        temp_sum_src += src_ptr[idx];
    }

    for (int i = 0; i < 4; ++i) {
        int32_t idx = indices[i] * ref_stride;
        temp_sum_ref += ref_ptr[idx];
    }

    // Dummy use of results
    temp_sum_src ^= temp_sum_ref;

    // Move to next 4-row block
    src_ptr += 4 * src_stride;
    ref_ptr += 4 * ref_stride;
}
}
