#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i--;) {
        uint32_t acc1 = 0, acc2 = 0;
        for (int j = 0; j < 4; j++) {
            acc1 += dst[j * dst_stride] * (j + 1);
            acc2 += dst[2 * j * dst_stride] + 5;
        }
        dst[0] = (uint8_t)(acc1 & 0xFF);
        dst[1] = (uint8_t)(acc2 & 0xFF);
        dst += (2 * dst_stride);
    }
}
