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
    dst[0] = temp_src[0];
    dst[stride] = temp_src[stride];
    dst[2*stride] = temp_src[2*stride];
    dst[3*stride] = temp_src[3*stride];
    src += (4 * stride);
    dst += (4 * stride);
}
}
