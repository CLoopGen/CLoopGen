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
    // Variant 2: Consecutive (Linearized) Memory Access with Pointer Arithmetic
    // Flatten the 2D iteration into a linear traversal using pointer arithmetic.
    // Process all rows as one long array, stepping by linesize to simulate row advances.
    // This improves predictability of memory access and enables better vectorization.

    uint16_t *dst_ptr = dst;
    uint16_t *top_ptr = top;
    uint16_t *bottom_ptr = bottom;

    for (i = 0; i < height; i++) {
        // Use local pointers to ensure consecutive access within the row
        uint16_t *d = dst_ptr;
        uint16_t *t = top_ptr;
        uint16_t *b = bottom_ptr;

        for (j = 0; j < width; j++) {
            d[j] = t[j] + (((t[j] + b[j]) / 2) - t[j]) * opacity;
        }

        // Advance pointers by linesize (in bytes or elements) for next row
        dst_ptr += dst_linesize;
        top_ptr += top_linesize;
        bottom_ptr += bottom_linesize;
    }
}
