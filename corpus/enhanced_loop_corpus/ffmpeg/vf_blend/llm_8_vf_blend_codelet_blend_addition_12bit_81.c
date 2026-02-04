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
    for (j = 0; j < width; j++) {
        int idx1 = j;
        int idx2 = j + width;
        dst[idx1] = top[idx1] + ((((4095) > (top[idx1] + bottom[idx1]) ? (top[idx1] + bottom[idx1]) : (4095))) - top[idx1]) * opacity;
        if (i + 1 < height) {
            dst[idx2] = top[idx2] + ((((4095) > (top[idx2] + bottom[idx2]) ? (top[idx2] + bottom[idx2]) : (4095))) - top[idx2]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
