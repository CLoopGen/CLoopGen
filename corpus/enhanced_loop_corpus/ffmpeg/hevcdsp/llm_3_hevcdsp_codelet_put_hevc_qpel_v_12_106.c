#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Index Array Emulation (simulating irregular access pattern)
    // Using precomputed offsets to simulate a more complex memory access pattern
    ptrdiff_t offsets[8] = {
        -3 * srcstride, -2 * srcstride, -1 * srcstride, 0,
          srcstride,   2 * srcstride,   3 * srcstride, 4 * srcstride
    };
    int16_t *dst_ptr = dst;
    uint16_t *src_ptr = src;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int32_t sum = 0;
            for (int k = 0; k < 8; k++) {
                sum += filter[k] * src_ptr[x + offsets[k]];
            }
            dst_ptr[x] = sum >> 4;
        }
        src_ptr += srcstride;
        dst_ptr += 64;
    }
}
