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
for (cnt = (height / 4); cnt--;) {
    int offset;
    // Access memory using a strided pattern across multiple rows simultaneously
    for (offset = 0; offset < 4; ++offset) {
        dst[offset * dst_stride]     = src[offset * src_stride];
        dst[offset * dst_stride + 1] = src[offset * src_stride + 1];
        dst[offset * dst_stride + 2] = src[offset * src_stride + 2];
        dst[offset * dst_stride + 3] = src[offset * src_stride + 3];
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
