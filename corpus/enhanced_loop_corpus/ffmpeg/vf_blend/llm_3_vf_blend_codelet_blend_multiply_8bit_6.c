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
    // Variant 2: Consecutive Pointer-Based Access with Local Temporaries
    uint8_t *top_row = top;
    uint8_t *bottom_row = bottom;
    uint8_t *dst_row = dst;

    for (i = 0; i < height; i++) {
        uint8_t *t = top_row;
        uint8_t *b = bottom_row;
        uint8_t *d = dst_row;

        for (j = 0; j < width; j++) {
            *d = *t + ((((1) * ((*t * *b) / 255)) - *t)) * opacity;
            d++; t++; b++;
        }

        top_row += top_linesize;
        bottom_row += bottom_linesize;
        dst_row += dst_linesize;
    }
}
