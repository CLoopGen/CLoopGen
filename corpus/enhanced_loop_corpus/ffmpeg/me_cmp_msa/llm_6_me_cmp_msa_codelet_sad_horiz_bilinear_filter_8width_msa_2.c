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
    uint8_t temp_src[8], temp_ref[8];
    int i;
    
    // Introduce local data dependencies: read-after-write (RAW) within the loop iteration
    for (i = 0; i < 8; ++i) {
        temp_src[i] = src[i * src_stride];
        temp_ref[i] = ref[i * ref_stride];
    }
    
    // Create artificial WAW dependency by writing and then overwriting a value
    int accumulator = 0;
    for (i = 0; i < 8; ++i) {
        accumulator += temp_src[i] + temp_ref[i];
    }
    accumulator *= 2;
    accumulator += 1;  // WAW on accumulator

    // Use result to affect memory update — introduces dependency chain
    if (accumulator > 100) {
        src[0] ^= accumulator;
        ref[0] ^= accumulator;
    }

    src += (4 * src_stride);
    ref += (4 * ref_stride);

    // Second block with similar structure but updated base pointers
    for (i = 0; i < 8; ++i) {
        temp_src[i] = src[i * src_stride];
        temp_ref[i] = ref[i * ref_stride];
    }

    accumulator = 0;
    for (i = 0; i < 8; ++i) {
        accumulator += temp_src[i] + temp_ref[i];
    }
    accumulator *= 2;
    accumulator += 1;

    if (accumulator > 100) {
        src[0] ^= accumulator;
        ref[0] ^= accumulator;
    }

    src += (4 * src_stride);
    ref += (4 * ref_stride);
}
}
