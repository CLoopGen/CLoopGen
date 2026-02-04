#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint8_t *in;
extern uint8_t *out;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access: process every second pixel (stride of 6 bytes in and out)
    int stride = 6; // Process every other RGB triplet
    for (j = 0; j < w; j++, out += stride, in -= stride) {
        if (j * 2 + 1 >= w) break; // Prevent overflow when accessing beyond array bounds

        // Access non-consecutive elements: treat input as strided
        const uint8_t* src = in - 3; // Simulate offset due to negative stride
        int32_t v = ((src[0] << 16) | (src[1] << 8) | src[2]);

        uint8_t* dst = out;
        dst[2] = v & 0xFF;
        dst[1] = (v >> 8) & 0xFF;
        dst[0] = (v >> 16) & 0xFF;
    }
}
