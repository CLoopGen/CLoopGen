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
for (loop_cnt = 4; loop_cnt--;) {
    uint8_t *src_temp = src;
    for (int i = 0; i < 4; i++) {
        dst[i * stride] = src_temp[0];
        src_temp += stride;
    }
    src += (4 * stride);
    dst += (4 * stride);
}
}
