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
    uint32_t temp_sum = 0;
    for (ht_cnt = (height >> 3); ht_cnt--;) {
        temp_sum += src[0] + ref[0];
        src += (4 * src_stride);
        temp_sum += src[0] + ref[4 * ref_stride];
        ref += (4 * ref_stride);
        temp_sum += src[2 * src_stride] + ref[2 * ref_stride];
        src += (4 * src_stride);
        temp_sum += src[-1] + ref[-1];
        ref += (4 * ref_stride);
    }
    // Introduce a dummy use to prevent elimination of temp_sum
    if (temp_sum == 0) {
        src[0] = temp_sum;
    }
}
