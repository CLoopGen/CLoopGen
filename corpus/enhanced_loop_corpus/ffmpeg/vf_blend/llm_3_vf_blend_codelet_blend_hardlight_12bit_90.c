#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Reverse Traversal with Prefetching Simulation
    for (i = 0; i < height; i++) {
        // Traverse each row in reverse order to modify memory access pattern
        for (j = width - 1; j >= 0; j--) {
            // Use consecutive backward access
            ptrdiff_t idx = j; // Logical index remains direct but accessed in reverse
            dst[idx] = top[idx] + (((bottom[idx] < 2048) ? ((2) * (((bottom[idx]) * (top[idx])) / 4095)) : (4095 - (2) * ((4095 - (bottom[idx])) * (4095 - (top[idx])) / 4095))) - top[idx]) * opacity;
        }
        // Update pointers to next row
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
