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
for (ht_cnt = (height >> 4); ht_cnt--;) {
    int inner_cnt;
    for (inner_cnt = 0; inner_cnt < 4; ++inner_cnt) {
        uint8_t temp_src = src[0];
        uint8_t temp_ref = ref[0];

        temp_src += temp_ref ^ 0x55;
        temp_ref += temp_src ^ 0xAA;

        src[0] = temp_src;
        ref[0] = temp_ref;

        src += src_stride / 2;
        ref += ref_stride / 2;

        {
            src[1] += ref[-1];
            ref[1] -= src[-1];
        }
    }

    src += (8 * src_stride);
    ref += (8 * ref_stride);
}
}
