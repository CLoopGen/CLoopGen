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
    int32_t i;
    // Change memory access pattern to use strided vector-like access with step
    for (i = 0; i < 8; ++i) {
        uint8_t s_val, r_val;
        int32_t idx = i * 2; // Stride of 2 across logical blocks

        // Access every other row in a scattered but predictable way
        s_val = src[(idx / 2) * src_stride];   // Example dummy read
        r_val = ref[(idx / 2) * ref_stride];   // Example dummy read

        (void)s_val; (void)r_val; // Avoid unused variable warning
    }

    // Advance both source and reference by full block height
    src += (8 * src_stride);
    ref += (8 * ref_stride);
}
}
