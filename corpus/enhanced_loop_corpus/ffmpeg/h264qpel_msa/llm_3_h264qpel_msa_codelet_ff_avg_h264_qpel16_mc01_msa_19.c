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
    ptrdiff_t offset;
    for (loop_cnt = 4; loop_cnt--;) {
        for (int i = 0; i < 4; i++) {
            offset = i * stride;
            dst[offset] = src[offset];
        }
        src += (4 * stride);
        dst += (4 * stride);
    }
}
