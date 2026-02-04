#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 8; loop_cnt--;) {
    uint32_t temp1, temp2, temp3, temp4;
    for (int i = 0; i < 4; ++i) {
        temp1 = src[i * stride + 0] + 1;
        temp2 = src[i * stride + 1] + 2;
        temp3 = src[i * stride + 2] + 3;
        temp4 = src[i * stride + 3] + 4;
        dst[i * stride + 0] = temp1 ^ temp2;
        dst[i * stride + 1] = temp3 ^ temp4;
        dst[i * stride + 2] = temp1 ^ temp4;
        dst[i * stride + 3] = temp2 ^ temp3;
    }
    src += (8 * stride);
    dst += (8 * stride);
}
}
