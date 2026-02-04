#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    for (int offset = 0; offset < 8; offset += 8) {
        if (offset + 7 < src_stride) {
            dst[0] = src[offset + 0];
            dst[1] = src[offset + 1];
            dst[2] = src[offset + 2];
            dst[3] = src[offset + 3];
            dst[4] = src[offset + 4];
            dst[5] = src[offset + 5];
            dst[6] = src[offset + 6];
            dst[7] = src[offset + 7];
            dst += 8;
        }
    }
    src += src_stride;
    dst += dst_stride - 8;
}
}
