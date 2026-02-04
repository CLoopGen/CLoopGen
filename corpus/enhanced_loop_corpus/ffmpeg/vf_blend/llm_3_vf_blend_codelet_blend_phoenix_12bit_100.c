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
    // Variant 2: Consecutive Block Access Using Pointer Arithmetic (unrolled-like consecutive access)
    uint16_t *top_row = top;
    uint16_t *bottom_row = bottom;
    uint16_t *dst_row = dst;

    for (i = 0; i < height; i++) {
        uint16_t *t = top_row;
        uint16_t *b = bottom_row;
        uint16_t *d = dst_row;

        // Traverse all elements consecutively using local pointers
        for (j = 0; j < width; j++) {
            d[j] = t[j] + ((((t[j]) > (b[j]) ? (b[j]) : (t[j])) - ((t[j]) > (b[j]) ? (t[j]) : (b[j])) + 4095) - t[j]) * opacity;
        }

        // Move to next row using linesizes
        top_row += top_linesize;
        bottom_row += bottom_linesize;
        dst_row += dst_linesize;
    }
}
