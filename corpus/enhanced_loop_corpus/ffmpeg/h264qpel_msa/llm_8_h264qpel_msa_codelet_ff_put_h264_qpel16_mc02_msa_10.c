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
    uint8_t temp1, temp2, temp3, temp4;
    for (int i = 0; i < 4; i++) {
        temp1 = src[i * stride];
        temp2 = src[i * stride + 1];
        temp3 = dst[i * stride];
        temp4 = dst[i * stride + 1];
        dst[i * stride] = temp1 ^ temp3;
        dst[i * stride + 1] = temp2 ^ temp4;
    }
    src += (8 * stride);
    dst += (8 * stride);
}
}
