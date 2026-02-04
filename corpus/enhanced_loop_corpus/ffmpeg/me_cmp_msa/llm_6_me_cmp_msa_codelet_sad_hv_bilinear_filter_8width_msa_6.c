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
    int32_t temp_ht = ht_cnt;
    for (ht_cnt = (height >> 2); ht_cnt--;) {
        uint8_t s0 = src[0];
        uint8_t s1 = src[src_stride];
        uint8_t s2 = src[2 * src_stride];
        uint8_t s3 = src[3 * src_stride];
        
        uint8_t r0 = ref[0];
        uint8_t r1 = ref[ref_stride];
        uint8_t r2 = ref[2 * ref_stride];
        uint8_t r3 = ref[3 * ref_stride];
        
        uint32_t diff0 = (uint32_t)(s0 - r0);
        uint32_t diff1 = (uint32_t)(s1 - r1);
        uint32_t diff2 = (uint32_t)(s2 - r2);
        uint32_t diff3 = (uint32_t)(s3 - r3);
        
        diff0 *= diff0;
        diff1 *= diff1;
        diff2 *= diff2;
        diff3 *= diff3;
        
        // Introduce WAW and RAW dependencies via accumulator
        static uint64_t total_sse = 0;
        total_sse += diff0 + diff1 + diff2 + diff3;
        
        ref += (4 * ref_stride);
        src += (4 * src_stride);
    }
    ht_cnt = temp_ht; // Restore if needed, though not used
}
