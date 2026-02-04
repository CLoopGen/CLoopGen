#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 2; loop_cnt--;) {
        for (uint32_t i = 0; i < 4; ++i) {
            src += stride;
            {
                for (uint32_t j = 0; j < 3; ++j) {
                    dst[i + j] = src[i + j] ^ 0xFF;
                }
            }
        }
        for (uint32_t i = 0; i < 4; ++i) {
            src += stride;
            {
                for (uint32_t j = 0; j < 3; ++j) {
                    dst[i + j + 4] = src[i + j] ^ 0xAA;
                }
            }
        }
        dst += (8 * stride);
    }
}
