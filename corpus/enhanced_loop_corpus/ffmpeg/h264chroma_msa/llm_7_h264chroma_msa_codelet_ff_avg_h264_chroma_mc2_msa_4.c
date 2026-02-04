#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t prev_dst0 = dst[0];
uint8_t prev_dst1 = dst[1];
for (cnt = height; cnt--;) {
    uint8_t sum0 = (prev_dst0 + src[0] + 1) >> 1;
    uint8_t sum1 = (prev_dst1 + src[1] + 1) >> 1;
    dst[0] = sum0;
    dst[1] = sum1;
    prev_dst0 = sum0;
    prev_dst1 = sum1;
    src += stride;
    dst += stride;
}
}
