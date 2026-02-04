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
    int32_t i;
    uint8_t temp_src, temp_ref;
    uint32_t accumulator = 0;

    for (ht_cnt = (height >> 2); ht_cnt--;) {
        // Introduce loop-carried dependency via accumulator
        temp_src = src[0];
        temp_ref = ref[0];
        accumulator += (uint32_t)(temp_src + temp_ref);

        // RAW dependency: current iteration uses result from previous via accumulator
        src[0] = (uint8_t)(accumulator & 0xFF);
        ref[0] = (uint8_t)((accumulator >> 8) & 0xFF);

        src += (4 * src_stride);
        ref += (4 * ref_stride);
    }

    // Prevent unused variable warning
    (void)accumulator;
}
