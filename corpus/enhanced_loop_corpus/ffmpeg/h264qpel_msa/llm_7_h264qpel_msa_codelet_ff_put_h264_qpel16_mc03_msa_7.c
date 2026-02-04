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
for (loop_cnt = 4; loop_cnt--;) {
    uint8_t val;
    ptrdiff_t offset = 4 * stride * loop_cnt;

    val = src[offset];
    dst[offset] = val ^ 0xFF;

    val = src[offset + stride];
    dst[offset + stride] = val ^ 0xFF;

    val = src[offset + 2 * stride];
    dst[offset + 2 * stride] = val ^ 0xFF;

    val = src[offset + 3 * stride];
    dst[offset + 3 * stride] = val ^ 0xFF;
}
}
