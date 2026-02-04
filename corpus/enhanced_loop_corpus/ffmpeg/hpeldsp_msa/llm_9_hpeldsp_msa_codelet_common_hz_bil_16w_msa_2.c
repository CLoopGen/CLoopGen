#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced trip count with simplified body and increased stride per iteration
for (loop_cnt = (height >> 4); loop_cnt--;) {
    // Perform fewer iterations but with more accumulated offset
    src += (16 * src_stride);
    dst += (8 * dst_stride);

    // Minimal computation to reduce intensity
    dst[-8 * dst_stride] = src[-16 * src_stride];
    dst[-7 * dst_stride] = src[-15 * src_stride];

    // Additional dummy arithmetic to retain some workload
    uint8_t temp = (dst[-8 * dst_stride] + dst[-7 * dst_stride]) & 0xFF;
    dst[-6 * dst_stride] = temp;
}
}
