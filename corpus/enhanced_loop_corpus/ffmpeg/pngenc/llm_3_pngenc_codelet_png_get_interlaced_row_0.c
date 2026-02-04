#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int width;
extern int x;
extern int mask;
extern int dst_x;
extern int j;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size 4
    // Instead of sequential x, access every 4th bit position, simulating a strided access pattern useful in vectorization or cache behavior studies.
    int stride = 4;
    int remainder = width % stride;
    int limit = width - remainder;

    // Strided loop
    for (x = 0; x < limit; x += stride) {
        for (int offset = 0; offset < stride; offset++) {
            int idx = x + offset;
            if (idx >= width) continue;

            j = (idx & 7);
            if ((mask << j) & 128) {
                b = (src[idx >> 3] >> (7 - j)) & 1;
                dst[dst_x >> 3] |= b << (7 - (dst_x & 7));
                dst_x++;
            }
        }
    }

    // Handle remaining elements not aligned to stride
    for (x = limit; x < width; x++) {
        j = (x & 7);
        if ((mask << j) & 128) {
            b = (src[x >> 3] >> (7 - j)) & 1;
            dst[dst_x >> 3] |= b << (7 - (dst_x & 7));
            dst_x++;
        }
    }
}
