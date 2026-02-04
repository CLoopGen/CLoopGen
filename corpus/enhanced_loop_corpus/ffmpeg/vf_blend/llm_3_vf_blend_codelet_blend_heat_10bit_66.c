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
    // Variant 2: Consecutive Access with Pointer Arithmetic (pre-incremented base pointers)
    uint16_t *top_row = top;
    uint16_t *bottom_row = bottom;
    uint16_t *dst_row = dst;

    for (i = 0; i < height; i++) {
        uint16_t *t = top_row;
        uint16_t *b = bottom_row;
        uint16_t *d = dst_row;

        for (j = 0; j < width; j++) {
            d[j] = t[j] + (((t[j] == 0) ? 0 : 1023 - ((((1023 - b[j]) * (1023 - b[j])) / t[j]) > (1023) ? (1023) : (((1023 - b[j]) * (1023 - b[j])) / t[j]))) - t[j]) * opacity;
        }

        top_row += top_linesize;
        bottom_row += bottom_linesize;
        dst_row += dst_linesize;
    }

    // Update global pointers to reflect final state (as original modifies externs)
    top = top_row;
    bottom = bottom_row;
    dst = dst_row;
}
