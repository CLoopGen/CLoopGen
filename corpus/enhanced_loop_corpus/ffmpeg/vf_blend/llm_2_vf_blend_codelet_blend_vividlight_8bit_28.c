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
    for (j = 0; j < width; j++) {
        ptrdiff_t idx = j;
        dst_row[idx] = top_row[idx] + (((top_row[idx] < 128) ? (((2 * top_row[idx]) == 0) ? (2 * top_row[idx]) : ((0) > (255 - ((255 - (bottom_row[idx])) << 8) / (2 * top_row[idx])) ? (0) : (255 - ((255 - (bottom_row[idx])) << 8) / (2 * top_row[idx])))) : (((2 * (top_row[idx] - 128)) == 255) ? (2 * (top_row[idx] - 128)) : ((255) > ((((bottom_row[idx]) << 8) / (255 - (2 * (top_row[idx] - 128))))) ? ((((bottom_row[idx]) << 8) / (255 - (2 * (top_row[idx] - 128))))) : (255)))) - top_row[idx]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
