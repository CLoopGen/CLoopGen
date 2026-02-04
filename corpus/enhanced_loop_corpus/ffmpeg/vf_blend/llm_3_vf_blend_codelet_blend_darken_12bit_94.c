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
    // Variant 2: Consecutive Block Memory Access with Pointer Arithmetic
    // Flatten the 2D iteration into a linear pointer walk over each row.
    // Use base pointers incremented per row, and process all elements via consecutive dereferencing.
    uint16_t *top_row, *bottom_row, *dst_row;
    for (i = 0; i < height; i++) {
        top_row = top;
        bottom_row = bottom;
        dst_row = dst;
        for (j = 0; j < width; j++) {
            // Direct consecutive access using pointer arithmetic
            *dst_row = *top_row + ((((*top_row) > (*bottom_row) ? (*bottom_row) : (*top_row))) - *top_row) * opacity;
            dst_row++;
            top_row++;
            bottom_row++;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
