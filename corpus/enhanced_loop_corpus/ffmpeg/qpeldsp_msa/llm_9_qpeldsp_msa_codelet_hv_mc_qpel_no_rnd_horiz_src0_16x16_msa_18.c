#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t i;
    for (loop_count = (height >> 3); loop_count--;) {
        for (i = 0; i < 8; i += 2) {
            dst[i * dst_stride] = src[i * src_stride] ^ 0xFF;
            dst[(i + 1) * dst_stride] = src[(i + 1) * src_stride] ^ 0xAA;
        }
        src += (8 * src_stride);
        dst += (8 * dst_stride);
    }
}
