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
    // Variant 1: Consecutive memory access with unrolled stride of 2
    // Access pattern changed to process two elements consecutively when possible, reducing branching and improving spatial locality.
    for (x = 0; x < width - 1; x += 2) {
        int j1 = (x & 7);
        int j2 = ((x + 1) & 7);
        int mask_shift1 = mask << j1;
        int mask_shift2 = mask << j2;

        if (mask_shift1 & 128) {
            b = (src[x >> 3] >> (7 - j1)) & 1;
            dst[dst_x >> 3] |= b << (7 - (dst_x & 7));
            dst_x++;
        }
        if (mask_shift2 & 128) {
            b = (src[(x + 1) >> 3] >> (7 - j2)) & 1;
            dst[dst_x >> 3] |= b << (7 - (dst_x & 7));
            dst_x++;
        }
    }
    // Handle last element if width is odd
    if (x < width) {
        j = (x & 7);
        if ((mask << j) & 128) {
            b = (src[x >> 3] >> (7 - j)) & 1;
            dst[dst_x >> 3] |= b << (7 - (dst_x & 7));
            dst_x++;
        }
    }
}
