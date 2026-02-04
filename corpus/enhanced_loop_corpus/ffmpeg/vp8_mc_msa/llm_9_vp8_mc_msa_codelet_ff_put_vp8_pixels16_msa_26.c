#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 3); cnt--;) {
    dst[0 * dst_stride] = src[0 * src_stride];
    dst[1 * dst_stride] = src[1 * src_stride];
    dst[2 * dst_stride] = src[2 * src_stride];
    dst[3 * dst_stride] = src[3 * src_stride];
    dst[4 * dst_stride] = src[4 * src_stride];
    dst[5 * dst_stride] = src[5 * src_stride];
    dst[6 * dst_stride] = src[6 * src_stride];
    dst[7 * dst_stride] = src[7 * src_stride];
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
