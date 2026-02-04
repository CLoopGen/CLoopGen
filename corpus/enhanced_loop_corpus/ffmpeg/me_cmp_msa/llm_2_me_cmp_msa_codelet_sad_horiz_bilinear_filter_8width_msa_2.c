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
    for (int i = 0; i < 8; i++) {
        // Consecutive memory access: process 8 rows in a blocked, sequential manner
        for (int j = 0; j < 4; j += 2) {
            uint8_t s0 = src0[j + 0];
            uint8_t s1 = src0[j + 1];
            uint8_t r0 = ref0[j + 0];
            uint8_t r1 = ref0[j + 1];
            // Dummy operations to simulate useful work
            s0 ^= r0;
            s1 ^= r1;
        }
        src0 += src_stride;
        ref0 += ref_stride;
    }
    src += (8 * src_stride);
    ref += (8 * ref_stride);
}
}
