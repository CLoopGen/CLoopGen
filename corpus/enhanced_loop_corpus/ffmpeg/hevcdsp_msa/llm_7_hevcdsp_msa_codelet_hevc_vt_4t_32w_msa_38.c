#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    // Create artificial loop-carried dependency via accumulator
    static int32_t acc = 0;

    // Load multiple source values with offset, create RAW dependencies
    uint8_t val0 = src[0];
    uint8_t val1 = src[src_stride];
    uint8_t val2 = src[2 * src_stride];
    uint8_t val3 = src[3 * src_stride];

    // Use accumulator to enforce WAW and loop-carried dependency
    acc += val0 + val1 + val2 + val3;
    int16_t computed_val = (int16_t)(acc & 0xFF);

    // Store to destination with stride; introduce WAR by reordering potential writes
    dst[0] = computed_val;
    dst[dst_stride] = computed_val + 1;
    dst[2 * dst_stride] = computed_val + 2;
    dst[3 * dst_stride] = computed_val + 3;

    // Update pointers in non-linear fashion to alter memory access pattern
    src += (4 * src_stride);
    dst += (4 * dst_stride);

    // Break regular update pattern slightly to increase complexity
    if ((acc % 2) == 0) {
        dst -= dst_stride;
    }
}
}
