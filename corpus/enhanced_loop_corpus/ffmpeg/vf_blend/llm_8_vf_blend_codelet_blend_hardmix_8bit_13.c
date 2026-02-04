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
for (i = 0; i < height; i++) {
    uint8_t *top_row = top;
    uint8_t *bottom_row = bottom;
    uint8_t *dst_row = dst;
    for (j = 0; j < width; j += 4) {
        dst_row[j]   = top_row[j] + (((top_row[j]   < (255 - bottom_row[j]))   ? 0 : 255) - top_row[j])   * opacity;
        dst_row[j+1] = top_row[j+1] + (((top_row[j+1] < (255 - bottom_row[j+1])) ? 0 : 255) - top_row[j+1]) * opacity;
        dst_row[j+2] = top_row[j+2] + (((top_row[j+2] < (255 - bottom_row[j+2])) ? 0 : 255) - top_row[j+2]) * opacity;
        dst_row[j+3] = top_row[j+3] + (((top_row[j+3] < (255 - bottom_row[j+3])) ? 0 : 255) - top_row[j+3]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
