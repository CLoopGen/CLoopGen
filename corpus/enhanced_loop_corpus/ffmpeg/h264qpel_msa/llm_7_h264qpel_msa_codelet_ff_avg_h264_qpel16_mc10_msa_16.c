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
ptrdiff_t offset = 0;
uint8_t value_accum = 0;
for (loop_cnt = 4; loop_cnt--;) {
    value_accum ^= src[offset];          
    value_accum ^= src[offset + stride];
    value_accum ^= src[offset + 2*stride];
    value_accum ^= src[offset + 3*stride];
    offset += 4 * stride;
}
dst[0] = value_accum;
for (loop_cnt = 4; loop_cnt--;) {
    dst[(4 - loop_cnt) * stride] = value_accum ^ 0xFF;
}
}
