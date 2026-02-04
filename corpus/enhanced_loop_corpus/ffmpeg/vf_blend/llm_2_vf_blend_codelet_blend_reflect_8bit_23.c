#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic and unrolled inner loop (factor of 2)
    uint8_t *top_row = top;
    uint8_t *bottom_row = bottom;
    uint8_t *dst_row = dst;
    for (i = 0; i < height; i++) {
        uint8_t *t = top_row;
        uint8_t *b = bottom_row;
        uint8_t *d = dst_row;
        j = 0;
        // Unroll by 2 for consecutive access and better locality
        for (; j + 1 < width; j += 2) {
            // First element
            d[0] = t[0] + (((b[0] == 255) ? b[0] : ((255) > ((t[0] * t[0] / (255.0 - b[0]))) ? ((t[0] * t[0] / (255.0 - b[0]))) : (255))) - t[0]) * opacity;
            // Second element
            d[1] = t[1] + (((b[1] == 255) ? b[1] : ((255) > ((t[1] * t[1] / (255.0 - b[1]))) ? ((t[1] * t[1] / (255.0 - b[1]))) : (255))) - t[1]) * opacity;
            t += 2; b += 2; d += 2;
        }
        // Handle remaining element if width is odd
        for (; j < width; j++) {
            d[0] = t[0] + (((b[0] == 255) ? b[0] : ((255) > ((t[0] * t[0] / (255.0 - b[0]))) ? ((t[0] * t[0] / (255.0 - b[0]))) : (255))) - t[0]) * opacity;
            t++; b++; d++;
        }
        top_row += top_linesize;
        bottom_row += bottom_linesize;
        dst_row += dst_linesize;
    }
}
