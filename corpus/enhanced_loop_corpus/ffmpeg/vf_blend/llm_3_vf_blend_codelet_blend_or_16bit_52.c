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
    // Variant 2: Consecutive Block Access with Pointer Arithmetic
    // Instead of indexing via [j], use direct pointer arithmetic to traverse each row consecutively.
    // This eliminates array index calculations and promotes consecutive memory access,
    // which is more friendly to prefetchers and vectorization.

    uint16_t *d, *t, *b;
    ptrdiff_t w = width;

    for (i = 0; i < height; i++) {
        d = dst;
        t = top;
        b = bottom;
        for (j = 0; j < w; j++) {
            *d = *t + ((*t | *b) - *t) * opacity;
            d++;
            t++;
            b++;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
