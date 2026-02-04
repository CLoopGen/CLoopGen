#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t *dst_ptr;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (height >> 2); cnt--;) {
        if (src_stride > 0) {
            src += (4 * src_stride);
        }
        if (dst_stride != 0) {
            dst_ptr += (4 * 2 * dst_stride);
        }
    }
}
