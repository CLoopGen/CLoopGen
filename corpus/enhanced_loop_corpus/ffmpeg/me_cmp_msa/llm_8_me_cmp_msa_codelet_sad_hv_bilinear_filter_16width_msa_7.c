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
for (ht_cnt = (height >> 2); ht_cnt--;) {
    src += (2 * src_stride);
    ref += (2 * ref_stride);
    
    // Increased computational density with arithmetic operations
    int32_t offset1 = (src[0] + src[1]) * 3;
    int32_t offset2 = (ref[0] - ref[1]) * 5;
    int32_t combined = (offset1 + offset2) & 0xFF;

    for (int i = 0; i < 4; ++i) {
        src[i * src_stride] ^= combined;
        ref[i * ref_stride] ^= (combined >> 4);
    }

    src += (2 * src_stride);
    ref += (2 * ref_stride);

    int32_t offset3 = (src[2] * 7) ^ 0xAA;
    int32_t offset4 = (ref[2] * 11) ^ 0x55;
    combined = (offset3 + offset4) & 0xFF;

    for (int i = 0; i < 4; ++i) {
        src[i * src_stride + 1] += combined;
        ref[i * ref_stride + 1] += (combined >> 4);
    }
}
}
