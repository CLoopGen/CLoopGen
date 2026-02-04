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
uint8_t *dst_row, *top_row, *bottom_row;
for (i = 0; i < height; i++) {
    dst_row = dst + i * dst_linesize;
    top_row = top + i * top_linesize;
    bottom_row = bottom + i * bottom_linesize;
    for (j = 0; j < width; j++) {
        uint8_t computed = bottom_row[j] == 255 ? 255 : (uint8_t)((double)(top_row[j] * top_row[j]) / (255.0 - bottom_row[j]));
        if (computed < 255) {
            dst_row[j] = (uint8_t)(top_row[j] + (computed - top_row[j]) * opacity);
        } else {
            dst_row[j] = (uint8_t)(top_row[j] + (255 - top_row[j]) * opacity);
        }
    }
}
}
