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
    // Variant 2: Consecutive pointer-based access using local pointers to improve locality
    // Uses temporary pointers advanced consecutively without repeated indexing
    uint16_t *d = dst;
    uint16_t *t = top;
    uint16_t *b = bottom;

    for (i = 0; i < height; i++) {
        uint16_t *d_row = d;
        uint16_t *t_row = t;
        uint16_t *b_row = b;

        for (j = 0; j < width; j++) {
            d_row[j] = t_row[j] + ((((65535 - t_row[j] - b_row[j]) >= 0 ? (65535 - t_row[j] - b_row[j]) : (-(65535 - t_row[j] - b_row[j])))) - t_row[j]) * opacity;
        }

        d = (uint16_t *)((char *)d + dst_linesize * sizeof(uint16_t));
        t = (uint16_t *)((char *)t + top_linesize * sizeof(uint16_t));
        b = (uint16_t *)((char *)b + bottom_linesize * sizeof(uint16_t));
    }
}
