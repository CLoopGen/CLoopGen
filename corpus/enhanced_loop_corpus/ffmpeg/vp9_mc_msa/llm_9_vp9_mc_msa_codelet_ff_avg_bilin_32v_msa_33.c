#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        for (int row = 0; row < 8; row += 4) {
            uint8_t *s_row = src + (row * src_stride);
            uint8_t *d_row = dst + (row * dst_stride);

            for (int col = 0; col < 32; col++) {
                uint32_t sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += s_row[col + k];
                }
                d_row[col] = (uint8_t)(sum / 4);
            }

            for (int col = 32; col < 64; col++) {
                uint32_t weighted = 0;
                weighted += s_row[col] * 4;
                weighted += s_row[col + 1] * 3;
                weighted += s_row[col + 2] * 2;
                weighted += s_row[col + 3];
                d_row[col] = (uint8_t)((weighted + 5) / 10);
            }
        }

        src += (8 * src_stride);
        dst += (8 * dst_stride);
    }
}
