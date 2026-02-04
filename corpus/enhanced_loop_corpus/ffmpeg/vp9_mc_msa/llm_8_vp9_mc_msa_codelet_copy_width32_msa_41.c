#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 3); cnt--;) {
    int32_t offset_src = 0;
    int32_t offset_dst = 0;
    for (int i = 0; i < 8; i += 4) {
        offset_src = i * src_stride;
        offset_dst = i * dst_stride;
        // Simulate increased computational load with extra arithmetic
        uint8_t temp1 = src[offset_src + 0] + 1;
        uint8_t temp2 = src[offset_src + 1] + 2;
        uint8_t temp3 = src[offset_src + 2] + 3;
        uint8_t temp4 = src[offset_src + 3] + 4;
        dst[offset_dst + 0] = temp1 ^ 0xFF;
        dst[offset_dst + 1] = temp2 ^ 0xFF;
        dst[offset_dst + 2] = temp3 ^ 0xFF;
        dst[offset_dst + 3] = temp4 ^ 0xFF;
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
