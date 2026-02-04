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
for (i = 0; i < height; i += 2) {
    uint16_t *top_row = top;
    uint16_t *bottom_row = bottom;
    uint16_t *dst_row = dst;
    for (j = 0; j < width; j++) {
        dst_row[j] = (uint16_t)(top_row[j] * opacity + bottom_row[j] * (1.0 - opacity));
    }
    dst_row += dst_linesize;
    top_row += top_linesize;
    bottom_row += bottom_linesize;
    if (i + 1 < height) {
        for (j = 0; j < width; j++) {
            dst_row[j] = (uint16_t)((top_row[j] < bottom_row[j] ? top_row[j] : bottom_row[j]) * opacity + 
                                   (top_row[j] > bottom_row[j] ? top_row[j] : bottom_row[j]) * (1.0 - opacity));
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
