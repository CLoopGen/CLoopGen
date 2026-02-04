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
    uint8_t temp1[8], temp2[8], temp3[8], temp4[8];
    for (int i = 0; i < 8; i++) {
        temp1[i] = src[i * src_stride];
        temp2[i] = src[i * src_stride + 1];
        temp3[i] = temp1[i] ^ temp2[i];
        dst[i * dst_stride] = temp3[i];
        dst[i * dst_stride + 1] = temp3[i] + 1;
    }
    for (int i = 0; i < 8; i++) {
        temp4[i] = src[i * src_stride + 2];
        dst[i * dst_stride + 2] = temp4[i] << 1;
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
