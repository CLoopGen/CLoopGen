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
extern uint8_t *dst_dup;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height / 8); cnt--;) {
    if (src_stride > 0) {
        src += (4 * src_stride);
    }
    if (dst_stride > 0) {
        dst_dup += (4 * dst_stride);
    }
    src += (4 * src_stride);
    dst_dup += (4 * dst_stride);
    if (dst_stride > 0) {
        dst += (4 * dst_stride);
    }
    dst += (4 * dst_stride);
}
}
