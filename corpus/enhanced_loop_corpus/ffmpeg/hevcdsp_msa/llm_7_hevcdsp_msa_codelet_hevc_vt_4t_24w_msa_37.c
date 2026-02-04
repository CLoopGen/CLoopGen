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
    // Introduce artificial loop-carried dependency via temporary accumulator
    static int16_t acc = 0;  // Simulates state carried across iterations

    acc += (int16_t)src[0];  // RAW: use before redef in same iteration
    dst[0] = acc;            // WAW: multiple writes to dst possible if unrolled
    acc = (int16_t)src[src_stride]; // WAR: overwrite after use

    dst[dst_stride] = acc;

    acc += (int16_t)src[2 * src_stride];
    dst[2 * dst_stride] = acc;

    acc = (int16_t)src[3 * src_stride]; 
    dst[3 * dst_stride] = acc;

    // Update pointers with stride jumps
    src += (4 * src_stride);
    dst += (4 * dst_stride);

    // Break potential infinite carry of 'acc' between loop calls
    // by resetting dependency (semantically valid if each call independent)
    acc = 0;
}
}
