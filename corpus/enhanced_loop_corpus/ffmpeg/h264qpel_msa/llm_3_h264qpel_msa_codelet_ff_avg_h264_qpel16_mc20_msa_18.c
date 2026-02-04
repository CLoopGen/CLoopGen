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
    uint8_t *temp_src = src;
    uint8_t *temp_dst = dst;
    for (int i = 0; i < 4; i++) {
        temp_dst[i * stride] = temp_src[i * stride];
    }
    src += (4 * stride);
    dst += (4 * stride);
}
}
