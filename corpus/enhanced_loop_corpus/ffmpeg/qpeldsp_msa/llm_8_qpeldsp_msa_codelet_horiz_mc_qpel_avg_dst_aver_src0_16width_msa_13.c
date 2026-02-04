#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_count = (height >> 3); loop_count--;) {
        uint32_t temp1, temp2, temp3, temp4;
        for (int i = 0; i < 4; ++i) {
            temp1 = src[i * src_stride + 0];
            temp2 = src[i * src_stride + 1];
            temp3 = src[i * src_stride + 2];
            temp4 = src[i * src_stride + 3];
            dst[i * dst_stride + 0] = (temp1 + temp2 + temp3 + temp4) >> 2;
            dst[i * dst_stride + 1] = (temp1 * 3 + temp2 * 2 + temp3) / 6;
        }
        for (int i = 4; i < 8; ++i) {
            temp1 = src[i * src_stride + 0];
            temp2 = src[i * src_stride + 1];
            temp3 = src[i * src_stride + 2];
            temp4 = src[i * src_stride + 3];
            dst[i * dst_stride + 0] = (temp1 ^ temp2) & (temp3 | temp4);
            dst[i * dst_stride + 1] = (temp1 + temp4) ^ (temp2 + temp3);
        }
        src += (8 * src_stride);
        dst += (8 * dst_stride);
    }
}
