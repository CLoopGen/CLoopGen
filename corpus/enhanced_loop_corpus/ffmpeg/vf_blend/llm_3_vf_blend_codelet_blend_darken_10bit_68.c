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
    // Variant 2: Consecutive Reverse Traversal with Local Accumulation
    // Traverse the row from right to left to modify memory access pattern.
    // Also uses a temporary local pointer to improve clarity and simulate base-offset changes.

    uint16_t *top_row, *bottom_row, *dst_row;

    for (i = 0; i < height; i++) {
        top_row = top;
        bottom_row = bottom;
        dst_row = dst;

        // Process row from last to first element (reverse consecutive access)
        for (j = width - 1; j >= 0; j--) {
            dst_row[j] = top_row[j] + (((bottom_row[j] < top_row[j] ? bottom_row[j] : top_row[j]) - top_row[j])) * opacity;
        }

        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
