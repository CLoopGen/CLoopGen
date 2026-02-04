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
    {
        if ((cnt % 2) == 0) {
            src += (4 * src_stride);
            dst_dup += (4 * dst_stride);
        } else {
            src += (2 * src_stride);
            dst_dup += (2 * dst_stride);
        }
    }
    src += (4 * src_stride);
    dst_dup += (4 * dst_stride);
    {
        if ((cnt % 3) != 0) {
            dst += (4 * dst_stride);
        } else {
            dst += (2 * dst_stride);
        }
    }
    dst += (4 * dst_stride);
}
}
