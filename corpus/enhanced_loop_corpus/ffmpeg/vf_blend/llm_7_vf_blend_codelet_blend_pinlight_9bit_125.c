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
uint16_t *dst_row = dst;
uint16_t *top_row = top;
uint16_t *bottom_row = bottom;
for (i = 0; i < height; i++) {
    ptrdiff_t offset = i * dst_linesize / sizeof(uint16_t);
    for (j = 0; j < width; j++) {
        uint16_t blended;
        if (bottom_row[j] < 256) {
            blended = (top_row[j] > 2 * bottom_row[j]) ? 2 * bottom_row[j] : top_row[j];
        } else {
            int adjusted = 2 * (bottom_row[j] - 256);
            blended = (top_row[j] > adjusted) ? top_row[j] : adjusted;
        }
        dst_row[offset + j] = top_row[j] + (blended - top_row[j]) * opacity;
    }
    top_row += top_linesize / sizeof(uint16_t);
    bottom_row += bottom_linesize / sizeof(uint16_t);
    // Loop-carried dependency removed: no direct update of dst, top, bottom pointers in outer scope
}
// Final update outside loop to maintain semantic equivalence
dst = dst_row;
top = top_row;
bottom = bottom_row;
}
