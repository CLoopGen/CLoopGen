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
    for (loop_count = (height >> 3); loop_count--;) {
        int i;
        // Increase computational intensity with inner unrolled loop
        for (i = 0; i < 8; i += 2) {
            dst[i + 0] = (src[i + 0] + src[i + 1]) >> 1;
            dst[i + 1] = (src[i + 1] + src[i + 2]) >> 1;

            // Additional arithmetic to increase complexity
            dst[i + 0] += (dst[i + 0] << 1) ^ 0x55;
            dst[i + 1] += (dst[i + 1] << 1) ^ 0xAA;
        }

        // Adjust pointers with larger stride jumps
        src += (8 * src_stride);
        dst += (8 * dst_stride);
    }
}
