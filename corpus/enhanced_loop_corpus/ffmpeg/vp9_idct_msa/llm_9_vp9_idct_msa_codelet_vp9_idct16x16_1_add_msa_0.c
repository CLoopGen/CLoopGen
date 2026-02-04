#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i--;) {
        dst[0 * dst_stride + 0] ^= 0xAA;
        dst[1 * dst_stride + 0] ^= 0x55;
        dst[2 * dst_stride + 0] ^= 0xAA;
        dst[3 * dst_stride + 0] ^= 0x55;
        dst[4 * dst_stride + 0] ^= 0xAA;
        dst[5 * dst_stride + 0] ^= 0x55;
        dst[6 * dst_stride + 0] ^= 0xAA;
        dst[7 * dst_stride + 0] ^= 0x55;

        for (int k = 0; k < 3; k++) {
            dst[k * dst_stride + 1] = dst[(k+1) * dst_stride + 0] + dst[(k+2) * dst_stride + 0];
        }

        dst += (8 * dst_stride);
    }
}
