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
for (i = 0; i < height; i++) {
    uint16_t *dst_row = dst + i * (dst_linesize / sizeof(uint16_t));
    uint16_t *top_row = top + i * (top_linesize / sizeof(uint16_t));
    uint16_t *bottom_row = bottom + i * (bottom_linesize / sizeof(uint16_t));
    for (j = 0; j < width; j++) {
        for (ptrdiff_t k = 0; k < 1; k++) {
            dst_row[j] = top_row[j] + ((top_row[j] & bottom_row[j]) - top_row[j]) * opacity;
        }
    }
}
}
