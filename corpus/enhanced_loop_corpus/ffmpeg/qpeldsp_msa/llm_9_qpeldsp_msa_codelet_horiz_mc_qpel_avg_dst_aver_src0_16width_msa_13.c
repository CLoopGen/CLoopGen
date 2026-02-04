#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 2;
    for (loop_count = (height >> 1); loop_count > 0; loop_count -= unroll_factor) {
        int remaining = (loop_count >= unroll_factor) ? unroll_factor : loop_count;
        for (int step = 0; step < remaining; ++step) {
            uint8_t val0 = src[0];
            uint8_t val1 = src[src_stride];
            uint8_t val2 = src[2 * src_stride];
            uint8_t val3 = src[3 * src_stride];

            uint32_t sum = val0 + val1 + val2 + val3;
            uint8_t avg = sum / 4;
            uint8_t smooth = (val0*2 + val1*3 + val2*3 + val3*2) / 10;

            dst[0] = avg;
            dst[dst_stride] = smooth;

            src += (4 * src_stride);
            dst += (2 * dst_stride);
        }
    }
}
