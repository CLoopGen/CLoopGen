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
    int32_t temp_src_offset = src_stride * 1;
    uint8_t val0 = src[0];
    uint8_t val1 = src[1];
    uint8_t val2 = src[2];
    uint8_t val3 = src[3];

    int16_t transformed0 = (int16_t)(val0 << 2);
    int16_t transformed1 = (int16_t)(val1 << 2);
    int16_t transformed2 = (int16_t)(val2 << 2);
    int16_t transformed3 = (int16_t)(val3 << 2);

    dst[0] = transformed0;
    dst[1] = transformed1;
    dst[2] = transformed2;
    dst[3] = transformed3;

    src += src_stride;
    dst += dst_stride;
}
}
