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
for (cnt = (height / 12); cnt--;) {
    int32_t i;
    uint8_t *src1 = src;
    uint8_t *dst1 = dst;

    for (i = 0; i < 8; i++) {
        dst1[i * dst_stride] = src1[i * src_stride];
        dst1[i * dst_stride + 1] = src1[i * src_stride + 1];
        dst1[i * dst_stride + 2] = src1[i * src_stride + 2];
        dst1[i * dst_stride + 3] = src1[i * src_stride + 3];
    }

    src += (8 * src_stride);
    dst += (8 * dst_stride);

    for (i = 0; i < 4; i++) {
        dst[i * dst_stride] = src[i * src_stride];
        dst[i * dst_stride + 1] = src[i * src_stride + 1];
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
