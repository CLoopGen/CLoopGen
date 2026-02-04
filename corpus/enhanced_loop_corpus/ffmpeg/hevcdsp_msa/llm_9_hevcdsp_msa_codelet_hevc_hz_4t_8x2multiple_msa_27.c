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
    int32_t i, j;
    const int32_t block_size = 4;
    for (i = 0; i < (height >> 1); i += block_size) {
        for (j = 0; j < block_size && (i + j) < (height >> 1); j++) {
            int32_t idx = (i + j) * 2;
            int32_t src_offset = idx * src_stride;
            int32_t dst_offset = idx * dst_stride;
            dst[dst_offset] = (int16_t)(src[src_offset] << 1);
            dst[dst_offset + dst_stride] = (int16_t)(src[src_offset + src_stride] << 1);
        }
    }
    src += (2 * (height >> 1) * src_stride);
    dst += (2 * (height >> 1) * dst_stride);
}
