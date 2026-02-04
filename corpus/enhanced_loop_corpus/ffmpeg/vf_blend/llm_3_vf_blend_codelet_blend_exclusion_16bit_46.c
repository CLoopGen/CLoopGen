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
    // Variant 2: Consecutive pointer-chasing access with pre-incremented pointers
    uint16_t *d = dst;
    uint16_t *t = top;
    uint16_t *b = bottom;
    for (i = 0; i < height; i++) {
        uint16_t *d_row = d;
        uint16_t *t_row = t;
        uint16_t *b_row = b;
        for (j = 0; j < width; j++) {
            d_row[j] = t_row[j] + ((t_row[j] + b_row[j] - 2 * t_row[j] * b_row[j] / 65535) - t_row[j]) * opacity;
        }
        d += dst_linesize;
        t += top_linesize;
        b += bottom_linesize;
    }
}
