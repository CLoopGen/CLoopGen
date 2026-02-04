#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective trip count and simplify body to decrease computational load
for (loop_cnt = (height >> 2); loop_cnt--;) {
    // Only one update per iteration, halving memory access frequency
    src += (src_stride << 1);
    dst += (dst_stride << 1);

    // Minimal computation: simple byte copy with light arithmetic
    uint8_t val = src[0] + 1;
    dst[0] = val;
}
}
