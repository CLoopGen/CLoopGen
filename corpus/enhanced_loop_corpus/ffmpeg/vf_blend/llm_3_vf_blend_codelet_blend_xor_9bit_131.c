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
    // Flatten inner loop into a single block using pointer arithmetic to promote consecutive memory access
    // This improves cache locality and enables better vectorization
    uint16_t *top_row, *bottom_row, *dst_row;
    ptrdiff_t w;

    for (i = 0; i < height; i++) {
        top_row = top;
        bottom_row = bottom;
        dst_row = dst;

        for (w = 0; w < width; w++) {
            dst_row[w] = top_row[w] + ((top_row[w] ^ bottom_row[w]) - top_row[w]) * opacity;
        }

        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
