#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Interleaved strided access: process multiple rows with stride jumps in inner loop
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        for (int offset = 0; offset < 4; ++offset) {
            // Access each of the 4 consecutive rows with increasing base offset
            uint8_t *s_row = src + offset * src_stride;
            uint8_t *d_row = dst + offset * dst_stride;

            // Assume unit stride along width (e.g., copy one pixel per column)
            d_row[0] = s_row[0];
            d_row[1] = s_row[1];
            d_row[2] = s_row[2];
            d_row[3] = s_row[3];
        }

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
