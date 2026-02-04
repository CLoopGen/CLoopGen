#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 3); cnt--;) {
    int i;
    for (i = 0; i < 8; i += 2) {
        dst[i * dst_stride] = src[i * src_stride];
        dst[i * dst_stride + 1] = src[i * src_stride + 1];
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
