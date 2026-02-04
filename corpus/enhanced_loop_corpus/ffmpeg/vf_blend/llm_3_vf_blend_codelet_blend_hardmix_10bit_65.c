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
    // Variant 2: Indirect Memory Access via Index Array
    // Use an explicitly defined index array to access dst, top, and bottom
    // in reverse order per row, creating a non-consecutive access pattern.
    ptrdiff_t *indices = (ptrdiff_t*)alloca(width * sizeof(ptrdiff_t));
    for (ptrdiff_t k = 0; k < width; k++) {
        indices[k] = width - 1 - k; // Reverse indexing
    }
    for (i = 0; i < height; i++) {
        for (ptrdiff_t k = 0; k < width; k++) {
            j = indices[k];
            dst[j] = top[j] + (((top[j] < (1023 - bottom[j])) ? 0 : 1023) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
