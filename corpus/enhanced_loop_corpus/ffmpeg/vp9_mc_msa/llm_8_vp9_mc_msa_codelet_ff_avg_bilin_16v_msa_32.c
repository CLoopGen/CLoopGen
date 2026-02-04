#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        uint32_t temp_sum = 0;
        for (int i = 0; i < 4; ++i) {
            temp_sum += src[i] * 3;
        }
        dst[0] = (uint8_t)(temp_sum >> 2);
        src += src_stride;
        dst += dst_stride;

        temp_sum = 0;
        for (int i = 0; i < 4; ++i) {
            temp_sum += src[i] * 3;
        }
        dst[0] = (uint8_t)(temp_sum >> 2);
        src += src_stride;
        dst += dst_stride;
    }
}
