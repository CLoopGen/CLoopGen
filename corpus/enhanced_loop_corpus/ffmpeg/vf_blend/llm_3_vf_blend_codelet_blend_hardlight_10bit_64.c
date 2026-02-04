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
ptrdiff_t *index_map = (ptrdiff_t*)alloca(width * sizeof(ptrdiff_t));
for (j = 0; j < width; j++) {
    index_map[j] = width - 1 - j; // Reverse index mapping
}
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        ptrdiff_t rev_j = index_map[j];
        dst[rev_j] = top[rev_j] + (((bottom[rev_j] < 512) ? ((2) * (((bottom[rev_j]) * (top[rev_j])) / 1023)) : (1023 - (2) * ((1023 - (bottom[rev_j])) * (1023 - (top[rev_j])) / 1023))) - top[rev_j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
