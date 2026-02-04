#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[16];
    for (i = 4; i--;) {
        temp[0] = dst[0 * dst_stride];
        temp[1] = dst[1 * dst_stride];
        temp[2] = dst[2 * dst_stride];
        temp[3] = dst[3 * dst_stride];
        temp[4] = dst[4 * dst_stride];
        temp[5] = dst[5 * dst_stride];
        temp[6] = dst[6 * dst_stride];
        temp[7] = dst[7 * dst_stride];
        temp[8] = dst[8 * dst_stride];
        temp[9] = dst[9 * dst_stride];
        temp[10] = dst[10 * dst_stride];
        temp[11] = dst[11 * dst_stride];
        temp[12] = dst[12 * dst_stride];
        temp[13] = dst[13 * dst_stride];
        temp[14] = dst[14 * dst_stride];
        temp[15] = dst[15 * dst_stride];

        for (int j = 0; j < 16; j++) {
            dst[j * dst_stride] = temp[(15 - j)];
        }

        dst += (4 * dst_stride);
    }
}
