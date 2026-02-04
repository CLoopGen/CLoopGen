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
for (cnt = (height / 8); cnt--;) {
    uint8_t temp_src[8];
    uint8_t temp_dst[8];
    int i;
    for (i = 0; i < 8; i++) {
        temp_src[i] = src[i * src_stride];
    }
    for (i = 0; i < 8; i++) {
        temp_dst[i] = temp_src[i] + 1;
    }
    for (i = 0; i < 8; i++) {
        dst[i * dst_stride] = temp_dst[i];
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
