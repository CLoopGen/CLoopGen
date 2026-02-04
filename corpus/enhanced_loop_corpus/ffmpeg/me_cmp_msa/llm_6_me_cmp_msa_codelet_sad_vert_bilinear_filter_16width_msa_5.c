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
    
    // Introduce local data dependencies: read-after-write (RAW) within the loop body
    for (i = 0; i < 8; ++i) {
        temp_src[i] = src[i * src_stride];
        temp_ref[i] = ref[i * ref_stride];
    }
    
    // Create WAW dependency by writing back in a dependent order
    for (i = 7; i >= 0; --i) {
        src[i * src_stride] = temp_src[(7 - i)] ^ 0xFF;
        ref[i * ref_stride] = temp_ref[(7 - i)] ^ 0x5A;
    }

    ref += (5 * ref_stride);
    src += (4 * src_stride);

    ref += (3 * ref_stride);
    src += (4 * src_stride);
}
}
