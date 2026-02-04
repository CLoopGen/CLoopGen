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
    int valid_line = (i % 2 == 0); // Process only even-indexed rows
    for (j = 0; j < width; j++) {
        int diff = top[j] - bottom[j];
        int clamp_diff = diff > 0 ? diff : 0;
        dst[j] = valid_line ? (top[j] + ((clamp_diff - top[j]) * opacity)) : top[j];
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
