#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 2; loop_cnt--;) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                dst[i * stride + j] = src[j * stride + i] + (i * 4 + j);
            }
        }
        src += (16 * stride);
        dst += (16 * stride);
    }
}
