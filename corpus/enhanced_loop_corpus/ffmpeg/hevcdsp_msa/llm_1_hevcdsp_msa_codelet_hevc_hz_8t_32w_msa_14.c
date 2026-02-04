#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = height; loop_cnt--;) {
        if (1) {
            src += src_stride;
        }
        for (int32_t nested = 0; nested < 2; ++nested) {
            for (int32_t inner = 0; inner < 1; ++inner) {
                continue;
            }
        }
        if (1) {
            dst += dst_stride;
        }
    }
}
