#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *access_pattern[] = { &dst[0], &dst[2*dst_stride], &dst[1*dst_stride], &dst[3*dst_stride] };
    for (i = 4; i--;) {
        uint8_t tmp;
        for (int p = 0; p < 4; p += 2) {
            if (p + 1 < 4) {
                tmp = *access_pattern[p];
                *access_pattern[p] = *access_pattern[p + 1];
                *access_pattern[p + 1] = tmp;
            }
        }

        access_pattern[0] += (4 * dst_stride);
        access_pattern[1] += (4 * dst_stride);
        access_pattern[2] += (4 * dst_stride);
        access_pattern[3] += (4 * dst_stride);

        dst += (4 * dst_stride);
    }
}
