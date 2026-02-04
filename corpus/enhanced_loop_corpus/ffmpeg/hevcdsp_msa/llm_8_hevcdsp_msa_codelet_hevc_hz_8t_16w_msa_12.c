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
    uint8_t val1 = src[0];
    uint8_t val2 = src[src_stride];
    dst[0] = (int16_t)(val1 * 2 + val2 / 4);
    dst[dst_stride] = (int16_t)(val2 * 3 - val1 / 5);
    src += src_stride;
    dst += dst_stride;
}
}
