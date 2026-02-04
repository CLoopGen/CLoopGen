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
    // Variant 2: Indirect (Indexed) Memory Access using index array
    // Simulate indirect access via precomputed indices (e.g., reverse traversal order)
    ptrdiff_t* indices = (ptrdiff_t*)alloca(width * sizeof(ptrdiff_t));
    for (j = 0; j < width; j++) {
        indices[j] = width - 1 - j; // Reverse order access
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ptrdiff_t idx = indices[j]; // Indirect indexing
            dst[idx] = top[idx] + ((((0) > (top[idx] - bottom[idx]) ? (0) : (top[idx] - bottom[idx]))) - top[idx]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
