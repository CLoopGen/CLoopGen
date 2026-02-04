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
            uint8_t val_top = src[i * src_stride];
            uint8_t val_bottom = src[(i + 1) * src_stride];

            dst[i * dst_stride] = (val_top ^ 0xFF) + 5;
            dst[(i + 1) * dst_stride] = (val_bottom ^ 0xFF) + 5;
        }
        src += (8 * src_stride);
        dst += (8 * dst_stride);
    }
}
