#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height >> 1; loop_cnt--;) {
    uint8_t val_top, val_bottom;
    int32_t offset = (loop_cnt & 3) * 4; 
    val_top = src[offset];
    val_bottom = src[src_stride + offset];
    dst[offset] = val_top + 1;
    dst[dst_stride + offset] = val_bottom + 1;
    src += (2 * src_stride);
    dst += (2 * dst_stride);
    val_top = val_bottom ^ val_top;
    val_bottom = 0;
}
}
