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
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        int32_t offset = loop_cnt * src_stride;
        uint8_t val1 = src[offset];
        uint8_t val2 = src[offset + 1];
        uint8_t val3 = src[offset + 2];
        uint8_t val4 = src[offset + 3];

        dst[loop_cnt * dst_stride] = (int16_t)(val1 * val1) - 128;
        dst[loop_cnt * dst_stride + 1] = (int16_t)(val2 * val2) - 128;
        dst[loop_cnt * dst_stride + 2] = (int16_t)(val3 * val3) - 128;
        dst[loop_cnt * dst_stride + 3] = (int16_t)(val4 * val4) - 128;
    }
}
