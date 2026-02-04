#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern  uint8_t *src;
extern int x;
extern int mask;
extern int dsp_mask;
extern int j;
extern int src_x;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Reverse Traversal
    // Processes every second element in reverse order to introduce strided and backward access pattern.
    // This changes spatial locality and may affect cache behavior.

    int stride = 2; // Process every 2nd element
    int effective_width = (width + stride - 1) & ~(stride - 1); // Round up for clean stride handling

    for (int x_rev = effective_width - 1; x_rev >= 0; x_rev -= stride) {
        // Map reversed, strided index back to logical x
        int x = width - 1 - (effective_width - 1 - x_rev);
        if (x >= width || x < 0) continue;

        int j = (x & 7);
        int mask_shifted = (mask << j) & 128;
        int dsp_shifted = (dsp_mask << j) & 128;

        if (dsp_shifted) {
            int b = (src[src_x >> 3] >> (7 - (src_x & 7))) & 1;
            dst[x >> 3] &= 65407 >> j;
            dst[x >> 3] |= b << (7 - j);
        }
        if (mask_shifted)
            src_x++;
    }
}
