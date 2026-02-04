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
uint8_t *top_row = top;
uint8_t *bottom_row = bottom;
uint8_t *dst_row = dst;
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        dst_row[j] = top_row[j] + (((((top_row[j]) == 0) ? (top_row[j]) : ((0) > (255 - ((255 - (bottom_row[j])) << 8) / (top_row[j])) ? (0) : (255 - ((255 - (bottom_row[j])) << 8) / (top_row[j]))))) - top_row[j]) * opacity;
    }
    dst_row += dst_linesize;
    top_row += top_linesize;
    bottom_row += bottom_linesize;
}
}
