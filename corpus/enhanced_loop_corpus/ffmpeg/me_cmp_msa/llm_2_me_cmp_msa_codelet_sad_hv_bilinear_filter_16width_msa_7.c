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
    uint8_t *src0 = src;
    uint8_t *ref0 = ref;
    for (int i = 0; i < 8; ++i) {
        uint8_t s_val = src0[i * src_stride];
        uint8_t r_val = ref0[i * ref_stride];
        // Simulate processing using consecutive conceptual access via indexing
        if (s_val != r_val) {
            // Dummy conditional to justify load
            src0[i * src_stride] = s_val ^ 1;
        }
    }
    src += (8 * src_stride);
    ref += (8 * ref_stride);
}
}
