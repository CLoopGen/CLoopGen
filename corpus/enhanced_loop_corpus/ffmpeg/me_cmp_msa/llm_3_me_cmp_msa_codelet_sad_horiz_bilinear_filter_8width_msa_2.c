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
    // Strided memory access: access every other row with increased stride
    uint8_t *src0 = src;
    uint8_t *ref0 = ref;
    for (int i = 0; i < 4; i++) {
        // Process two non-consecutive blocks with larger stride steps
        for (int j = 0; j < 8; j += 4) {
            uint8_t s0 = src0[j];
            uint8_t s4 = src0[j + 4];
            uint8_t r0 = ref0[j];
            uint8_t r4 = ref0[j + 4];
            // Simulate computation
            s0 ^= r0;
            s4 ^= r4;
        }
        src0 += (2 * src_stride);
        ref0 += (2 * ref_stride);
    }
    // Advance by full block height using original stride
    src += (8 * src_stride);
    ref += (8 * ref_stride);
}
}
