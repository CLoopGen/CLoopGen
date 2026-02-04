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
    // Variant 2: Indirect Memory Access using index array (simulated via pointer arithmetic)
    ptrdiff_t *indices = (ptrdiff_t*)alloca(width * sizeof(ptrdiff_t));
    for (j = 0; j < width; j++) {
        indices[j] = j; // identity mapping for indirect access
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ptrdiff_t idx = indices[j]; // use indirect index
            dst[idx] = top[idx] + ((top[idx] ^ bottom[idx]) - top[idx]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
