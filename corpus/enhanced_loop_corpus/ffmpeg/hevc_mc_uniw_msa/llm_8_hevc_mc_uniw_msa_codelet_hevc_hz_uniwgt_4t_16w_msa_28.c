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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint32_t temp1, temp2, temp3, temp4;
    for (int i = 0; i < 4; ++i) {
        temp1 = src[i * src_stride + 0];
        temp2 = src[i * src_stride + 1];
        temp3 = src[i * src_stride + 2];
        temp4 = src[i * src_stride + 3];
        
        dst[i * dst_stride + 0] = (temp1 + temp2 + temp3 + temp4) / 4;
        dst[i * dst_stride + 1] = (temp1 * 0.3f + temp2 * 0.4f + temp3 * 0.2f + temp4 * 0.1f);
        dst[i * dst_stride + 2] = temp1 > 128 ? temp3 : temp4;
        dst[i * dst_stride + 3] = (temp1 ^ temp2) & 0xFF;
    }
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
