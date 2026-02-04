#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t temp[8];
        for (int i = 0; i < 8; ++i) {
            temp[i] = src[i * src_stride];
        }
        for (int i = 0; i < 8; ++i) {
            dst[i * dst_stride] = temp[(7 - i)];
        }
        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
