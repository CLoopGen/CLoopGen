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
    if (height < 8) {
        for (loop_cnt = height; loop_cnt--;) {
            dst[0] = src[0];
            dst[1] = src[1];
            src += src_stride;
            dst += dst_stride;
        }
    } else {
        loop_cnt = (height >> 3);
        while (loop_cnt--) {
            for (int j = 0; j < 8; ++j) {
                for (int i = 0; i < 4; ++i) {
                    dst[i] = src[i] ^ 0xFF; // Invert bytes
                }
                src += src_stride;
                dst += dst_stride;
            }
        }
        // Handle remainder
        for (int r = height & 7; r--; ) {
            dst[0] = src[0];
            src += src_stride;
            dst += dst_stride;
        }
    }
}
