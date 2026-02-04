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
    // Variant 2: Consecutive block access using pointer arithmetic with local pointers
    uint8_t *d = dst;
    uint8_t *t = top;
    uint8_t *b = bottom;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            d[j] = t[j] + ((t[j] & b[j]) - t[j]) * opacity;
        }
        d += dst_linesize;
        t += top_linesize;
        b += bottom_linesize;
    }
}
