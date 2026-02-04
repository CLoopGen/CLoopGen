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
    int32_t i, j;
    for (loop_count = (height >> 2); loop_count--;) {
        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 4; ++j) {
                dst[i * dst_stride + j] = src[i * src_stride + j] ^ 0xFF;
            }
        }
        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
