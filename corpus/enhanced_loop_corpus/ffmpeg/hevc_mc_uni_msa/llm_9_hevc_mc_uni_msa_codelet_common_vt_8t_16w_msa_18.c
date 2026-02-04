#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t i, j;
    const int32_t block_size = 2;
    for (i = 0; i < height; i += block_size) {
        for (j = 0; j < block_size && (i + j) < height; ++j) {
            uint8_t val = src[j * src_stride];
            val = (val << 1) | (val >> 7);
            val ^= 0xFF;
            dst[j * dst_stride] = val;
            
            val = src[j * src_stride + 1];
            val = (val << 2) | (val >> 6);
            val ^= 0x80;
            dst[j * dst_stride + 1] = val;
        }
        src += (block_size * src_stride);
        dst += (block_size * dst_stride);
    }
}
