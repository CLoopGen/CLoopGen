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
    // Variant 2: Consecutive Pointer-Based Access (use local pointers with pre-increment)
    for (i = 0; i < height; i++) {
        uint16_t *d = dst;
        uint16_t *t = top;
        uint16_t *b = bottom;
        for (j = 0; j < width; j++) {
            *d++ = *t + ((((0) > (*t - *b) ? (0) : (*t - *b))) - *t) * opacity;
            t++;
            b++;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
